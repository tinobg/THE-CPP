#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <climits>

class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);

    float getExchangeRate(const std::string& date);
    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& value);
};

#endif
