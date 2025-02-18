#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Could not open database file." << std::endl;
        return false;
    }

    std::string line, date;
    float rate;

    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        if (!std::getline(ss, date, ',') || !(ss >> rate)) continue;
        exchangeRates[date] = rate;
    }
    return !exchangeRates.empty();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    int year, month, day;
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) return false;
    if (year < 2000 || year > 2030 || month < 1 || month > 12 || day < 1) return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isValidValue(const std::string& value) {
    if (value.empty()) {
        std::cerr << "Error: Empty value." << std::endl;
        return false;
    }

    char* end;
    double val = strtod(value.c_str(), &end);
    if (*end != '\0' && *end != ' ') {
        std::cerr << "Error: Invalid number format." << std::endl;
        return false;
    }
    if (val < 0) {
        std::cerr << "Error: Not a positive number." << std::endl;
        return false;
    }
    if (val > INT_MAX) {
        std::cerr << "Error: Too large a number." << std::endl;
        return false;
    }

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) {
    std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.end() || it->first != date) {
        if (it == exchangeRates.begin()) return -1;
        --it;
    }
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line, date, value;
    if (!std::getline(file, line) || line != "date | value") {
        std::cerr << "Error: Invalid or empty file." << std::endl;
        return;
    }

    bool hasValidData = false;
    while (std::getline(file, line)) {
        if (line.empty() || line.find('|') == std::string::npos) continue;

        std::stringstream ss(line);
        std::getline(ss, date, '|');
        std::getline(ss, value);

        date.erase(date.find_last_not_of(" ") + 1);
        date.erase(0, date.find_first_not_of(" "));
        value.erase(value.find_last_not_of(" ") + 1);
        value.erase(0, value.find_first_not_of(" "));

        if (!isValidDate(date)) {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(value)) continue;

        float val = atof(value.c_str());
        float rate = getExchangeRate(date);
        if (rate == -1) {
            std::cerr << "Error: No exchange rate available for " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << val << " = " << (val * rate) << std::endl;
        hasValidData = true;
    }

    if (!hasValidData) std::cerr << "Error: No valid data found in file." << std::endl;
}
