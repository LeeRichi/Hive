#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    private:
    std::vector<int> vec;
    std::deque<int> deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        // Add elements
        void addNumber(int val);

        template <typename Container>
        void FordJohnson(Container& container, int left, int right);

        // Accessors for output
        std::vector<int>& getVector();
        std::deque<int>& getDeque();
};

#include "PmergeMe.tpp"
