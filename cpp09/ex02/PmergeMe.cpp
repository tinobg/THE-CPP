#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::mergeInsertSort(T& arr) {
    if (arr.size() <= 1)
        return;

    T sortedLarger, sortedSmaller;
    createSortedPairs(arr, sortedLarger, sortedSmaller);
    mergeInsertSort(sortedLarger);
    insertSmallerElements(sortedLarger, sortedSmaller);
    arr.swap(sortedLarger);
}

template <typename T>
void PmergeMe::createSortedPairs(T& arr, T& sortedLarger, T& sortedSmaller) {
    typename T::iterator it = arr.begin();
    while (it != arr.end()) {
        typename T::iterator first = it++;
        if (it != arr.end()) {
            typename T::iterator second = it++;
            if (*first > *second)
                std::iter_swap(first, second);
            sortedSmaller.push_back(*first);
            sortedLarger.push_back(*second);
        } else {
            sortedLarger.push_back(*first);
        }
    }
}

template <typename T>
void PmergeMe::insertSmallerElements(T& sortedLarger, T& sortedSmaller) {
    std::vector<int> jacobsthalSeq = precomputeJacobsthal(sortedSmaller.size());

    typename T::iterator it = sortedSmaller.begin();
    for (size_t i = 0; i < sortedSmaller.size(); ++i) {
        size_t index = jacobsthalSeq[i % jacobsthalSeq.size()];
        if (index >= sortedSmaller.size())
            index = sortedSmaller.size() - 1;

        typename T::iterator pos = binarySearchInsert(sortedLarger, *it);
        sortedLarger.insert(pos, *it);
        ++it;
    }
}

template <typename T>
typename T::iterator PmergeMe::binarySearchInsert(T& sorted, int value) {
    typename T::iterator low = sorted.begin(), high = sorted.end();
    while (low != high) {
        typename T::iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        if (*mid < value)
            low = ++mid;
        else
            high = mid;
    }
    return low;
}

template <>
std::deque<int>::iterator PmergeMe::binarySearchInsert(std::deque<int>& sorted, int value) {
    std::deque<int>::iterator low = sorted.begin(), high = sorted.end();
    while (low != high) {
        std::deque<int>::iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        if (*mid < value)
            low = ++mid;
        else
            high = mid;
    }
    return low;
}

std::vector<int> PmergeMe::precomputeJacobsthal(int max) {
    std::vector<int> jacobsthalNumbers;
    jacobsthalNumbers.push_back(1);
    jacobsthalNumbers.push_back(3);

    while (true) {
        int nextJ = jacobsthalNumbers[jacobsthalNumbers.size() - 1] +
                    2 * jacobsthalNumbers[jacobsthalNumbers.size() - 2];
        if (nextJ > max)
            break;
        jacobsthalNumbers.push_back(nextJ);
    }
    return jacobsthalNumbers;
}

void PmergeMe::sort(std::vector<int>& arr) {
    mergeInsertSort(arr);
}

void PmergeMe::sort(std::deque<int>& arr) {
    mergeInsertSort(arr);
}
