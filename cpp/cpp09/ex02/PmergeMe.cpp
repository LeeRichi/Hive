#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : unit_size(0) {}

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

std::vector<int>& PmergeMe::getVector() {
	return vec;
}

void PmergeMe::setSize (size_t size) {
		if (size <= 0) {
				std::cerr << "Error: Size must be positive." << std::endl;
				exit(1);
		}
		unit_size = size;
}

std::deque<int>& PmergeMe::getDeque() {
	return deq;
}
