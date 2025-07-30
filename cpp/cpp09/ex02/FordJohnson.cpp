#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &og)
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

void insertionSort(std::vector<int>& winners, std::vector<int>& losers, const std::vector<int>& jacobsthalNumbers) {
	std::vector<bool> inserted(losers.size(), false);

	for (int idx : jacobsthalNumbers) {
		if (idx >= (int)losers.size()) continue;
		int key = losers[idx];
		auto pos = std::upper_bound(winners.begin(), winners.end(), key);
		winners.insert(pos, key);
		inserted[idx] = true;
	}

	// Insert remaining losers
	for (int i = 0; i < (int)losers.size(); ++i) {
		if (!inserted[i]) {
			int key = losers[i];
			auto pos = std::upper_bound(winners.begin(), winners.end(), key);
			winners.insert(pos, key);
		}
	}
}

std::vector<int> Jacobsthal(int n) {
	std::vector<int> sequence;
	sequence.push_back(0);  // J0
	if (n == 0) return sequence;
	sequence.push_back(1);  // J1

	int i = 2;
	while (true) {
			int next = sequence[i - 1] + 2 * sequence[i - 2];
			if (next >= n)
					break;
			if (next != sequence.back())
				sequence.push_back(next);
			i++;
	}
	return sequence;
}

void InsertLosersToWinners(std::vector<int>& winners, std::vector<int>& losers)
{
	std::vector<int> JacobsthalNumber = Jacobsthal(losers.size());

	insertionSort(winners, losers, JacobsthalNumber);
}

void PmergeMe::FordJohnson(std::vector<int>& vec, int left, int right)
{
    if (left >= right)
        return;

		std::vector<int> winners;
		std::vector<int> losers;

		//compete neighbor by pairing them
		for (int i = left; i + 1 <= right; i += 2) {
			if (vec[i] > vec[i + 1]) {
				winners.push_back(vec[i]);
				losers.push_back(vec[i + 1]);
			} else {
				winners.push_back(vec[i + 1]);
				losers.push_back(vec[i]);
			}
		}
		// Handle leftover element if `vec` has odd length by push it to winners
		if ((right - left + 1) % 2 != 0)
			winners.push_back(vec[right]);

		// Recursivly sort winners
		FordJohnson(winners, 0, (int)winners.size() - 1);

		InsertLosersToWinners(winners, losers);

		// Copy back merged sorted data to original vector segment
		std::copy(winners.begin(), winners.begin() + (right - left + 1), vec.begin() + left);
	}

std::vector<int>& PmergeMe::getVector() {
	return vec;
}

std::deque<int>& PmergeMe::getDeque() {
	return deq;
}
