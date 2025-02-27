#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sort(std::vector<int>& arr);
    void sort(std::deque<int>& arr);
    
private:
    template <typename T>
    void createSortedPairs(T& arr, T& sortedLarger, T& sortedSmaller);

    template <typename T>
    void mergeInsertSort(T& arr);

    template <typename T>
    void insertSmallerElements(T& sortedLarger, T& sortedSmaller);

    template <typename T>
    typename T::iterator binarySearchInsert(T& sorted, int value);

    std::vector<int> precomputeJacobsthal(int max);
};

#endif
