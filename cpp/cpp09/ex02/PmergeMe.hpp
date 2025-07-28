#pragma once

#include <vector>
#include <deque>

const int INSERTION_SORT_THRESHOLD = 16;

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

      // Sorting functions (you'll define these)
      void mergeInsertSortVector(std::vector<int>& vec, int left, int right);
      void mergeInsertSortDeque(std::deque<int>& deque, int left, int right);

      // Accessors for output
      std::vector<int>& getVector();
      std::deque<int>& getDeque();
};
