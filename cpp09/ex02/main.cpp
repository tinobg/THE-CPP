#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <list of numbers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        vec.push_back(num);
        lst.push_back(num);
    }

    PmergeMe sorter;

    std::cout << "Before sorting: ";
    for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Measure sorting time for vector
    clock_t startVec = clock();
    sorter.sort(vec);
    clock_t endVec = clock();

    // Measure sorting time for list
    clock_t startLst = clock();
    sorter.sort(lst);
    clock_t endLst = clock();

    std::cout << "After sorting (vector): ";
    for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;
    
    std::cout << "After sorting (list): ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    double vecTime = double(endVec - startVec) / CLOCKS_PER_SEC;
    double lstTime = double(endLst - startLst) / CLOCKS_PER_SEC;

    std::cout << "Sorting time (vector): " << vecTime << " sec" << std::endl;
    std::cout << "Sorting time (list): " << lstTime << " sec" << std::endl;

    return 0;
}
