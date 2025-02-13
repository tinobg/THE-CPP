#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::mergeInsertSort(T& arr) {
    if (arr.size() <= 1) return;

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
        int a = *it;
        ++it;
        if (it != arr.end()) {
            int b = *it;
            ++it;
            if (a > b) std::swap(a, b);
            sortedSmaller.push_back(a);
            sortedLarger.push_back(b);
        } else {
            sortedLarger.push_back(a);
        }
    }
}

template <typename T>
void PmergeMe::insertSmallerElements(T& sortedLarger, T& sortedSmaller) {
    size_t smallerSize = sortedSmaller.size();
    typename T::iterator it = sortedSmaller.begin();

    for (size_t i = 0; i < smallerSize; ++i) {
        size_t index = jacobsthal(i);
        if (index >= smallerSize) index = smallerSize - 1;

        typename T::iterator pos = binarySearchInsert(sortedLarger, *it);
        sortedLarger.insert(pos, *it);
        ++it;
    }
}

template <typename T>
typename T::iterator PmergeMe::binarySearchInsert(T& sorted, int value) {
    return std::lower_bound(sorted.begin(), sorted.end(), value);
}

template <>
std::list<int>::iterator PmergeMe::binarySearchInsert(std::list<int>& sorted, int value) {
    std::list<int>::iterator low = sorted.begin(), high = sorted.end();
    while (low != high) {
        std::list<int>::iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        if (*mid < value)
            low = ++mid;
        else
            high = mid;
    }
    return low;
}

int PmergeMe::jacobsthal(int n) {
    static int jacobsthalNumbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
    if (n < 11) return jacobsthalNumbers[n];
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sort(std::vector<int>& arr) {
    mergeInsertSort(arr);
}

void PmergeMe::sort(std::list<int>& arr) {
    mergeInsertSort(arr);
}
