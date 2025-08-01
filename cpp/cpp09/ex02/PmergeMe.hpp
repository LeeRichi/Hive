#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    private:
    std::vector<int> vec;
    std::deque<int> deq;

    size_t unit_size;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // Add elements
    void addNumber(int val);

    template <typename Container>
    void FordJohnson(Container &container, int left, int right);

    // Accessors for output
    std::vector<int> &getVector();
    void setSize(size_t size);
    std::deque<int> &getDeque();

};

#include "PmergeMe.tpp"
