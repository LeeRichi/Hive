#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& og)
{
	if (this != &og)
	{
		this->vec = og.vec;
		this->deq = og.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int val)
{
	vec.push_back(val);
	deq.push_back(val);
}


// old

// void insertionSort(std::vector<int> &vec, int left, int right) {
// 	for (int i = left + 1; i <= right; ++i)
// 	{
// 		int key = vec[i];
// 		int j = i - 1;

// 		while (j >= left && vec[j] > key) {
// 			vec[j + 1] = vec[j];
// 			--j;
// 		}
// 		vec[j + 1] = key;
// 	}
// }

// void mergeSort(std::vector<int>& vec, int left, int mid, int right)
// {
// 	std::vector<int> left_vec(vec.begin() + left, vec.begin() + mid + 1);
// 	std::vector<int> right_vec(vec.begin() + mid + 1, vec.begin() + right + 1);

// 	size_t i = 0, j = 0;
// 	int k = left;

// 	while (i < left_vec.size() && j < right_vec.size())
// 	{
// 		if (left_vec[i] <= right_vec[j])
// 			vec[k++] = left_vec[i++];
// 		else
// 			vec[k++] = right_vec[j++];
// 	}

// 	while (i < left_vec.size()) vec[k++] = left_vec[i++];
// 	while (j < right_vec.size()) vec[k++] = right_vec[j++];
// }

// void PmergeMe::mergeInsertSortVector(std::vector<int>& vec, int left, int right)
// {
// 	if (right - left <= INSERTION_SORT_THRESHOLD)
// 	{
// 		insertionSort(vec, left, right);
// 		return;
// 	}

// 	int mid = left + (right - left) / 2;
// 	mergeInsertSortVector(vec, left, mid);
// 	mergeInsertSortVector(vec, mid + 1, right);
// 	mergeSort(vec, left, mid, right);
// }

// void insertionSort(std::deque<int>& deq, int left, int right) {
// 	for (int i = left + 1; i <= right; ++i) {
// 		int key = deq[i];
// 		int j = i - 1;

// 		while (j >= left && deq[j] > key) {
// 			deq[j + 1] = deq[j];
// 			--j;
// 		}
// 		deq[j + 1] = key;
// 	}
// }

// void mergeSort(std::deque<int>& deq, int left, int mid, int right) {
// 	std::deque<int> left_deq, right_deq;

// 	for (int i = left; i <= mid; ++i)
// 		left_deq.push_back(deq[i]);
// 	for (int i = mid + 1; i <= right; ++i)
// 		right_deq.push_back(deq[i]);

// 	size_t i = 0, j = 0;
// 	int k = left;

// 	while (i < left_deq.size() && j < right_deq.size()) {
// 		if (left_deq[i] <= right_deq[j])
// 			deq[k++] = left_deq[i++];
// 		else
// 			deq[k++] = right_deq[j++];
// 	}

// 	while (i < left_deq.size()) deq[k++] = left_deq[i++];
// 	while (j < right_deq.size()) deq[k++] = right_deq[j++];
// }

// void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq, int left, int right) {
// 	if (right - left <= INSERTION_SORT_THRESHOLD) {
// 		insertionSort(deq, left, right);
// 		return;
// 	}

// 	int mid = left + (right - left) / 2;
// 	mergeInsertSortDeque(deq, left, mid);
// 	mergeInsertSortDeque(deq, mid + 1, right);
// 	mergeSort(deq, left, mid, right);
// }


std::vector<int>& PmergeMe::getVector() {
	return vec;
}

std::deque<int>& PmergeMe::getDeque() {
	return deq;
}
