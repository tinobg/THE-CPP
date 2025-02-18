#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <cerrno>
#include <climits>

bool isValidNumber(const char* str, int& result) {
    char* endptr;
    errno = 0;
    long num = std::strtol(str, &endptr, 10);

    if (*endptr != '\0' || str == endptr) {
        std::cerr << "Error: Invalid input '" << str << "'" << std::endl;
        return false;
    }

    if (errno == ERANGE || num > INT_MAX || num < INT_MIN) {
        std::cerr << "Error: Number too large or too small: '" << str << "'" << std::endl;
        return false;
    }

    result = static_cast<int>(num);
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <list of numbers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        int num;
        if (!isValidNumber(argv[i], num))
            return 1;
        vec.push_back(num);
        deq.push_back(num);
    }

    PmergeMe sorter;

    std::cout << "Before sorting: ";
    for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    sorter.sort(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sorter.sort(deq);
    clock_t endDeq = clock();

    std::cout << "After sorting (vector): ";
    for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "After sorting (deque): ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    double vecTime = double(endVec - startVec) / CLOCKS_PER_SEC;
    double deqTime = double(endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Sorting time (vector): " << vecTime << " sec" << std::endl;
    std::cout << "Sorting time (deque): " << deqTime << " sec" << std::endl;

    return 0;
}
