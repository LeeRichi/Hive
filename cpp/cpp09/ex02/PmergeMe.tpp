#include <algorithm>
#include "PmergeMe.hpp"

template <typename Container>
static std::vector<int> Jacobsthal(int n) {
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

template <typename Container>
void insertionSort(Container& winners, Container& losers, const std::vector<int>& jacobsthal) {
    std::vector<bool> inserted(losers.size(), false);

    for (int idx : jacobsthal) {
        // if (idx >= static_cast<int>(losers.size())) continue;
        if (idx < 0 || idx >= static_cast<int>(losers.size())) continue;  // ✅ prevent OOB
        auto pos = std::upper_bound(winners.begin(), winners.end(), losers[idx]);
        winners.insert(pos, losers[idx]);
        inserted[idx] = true;
    }

    for (size_t i = 0; i < losers.size(); ++i) {
        if (!inserted[i]) {
            auto pos = std::upper_bound(winners.begin(), winners.end(), losers[i]);
            winners.insert(pos, losers[i]);
        }
    }
}

template <typename Container>
void InsertLosersToWinners(Container& winners, Container& losers) {
	std::vector<int> jacobsthal = Jacobsthal<Container>(losers.size());
	insertionSort(winners, losers, jacobsthal);
}

template <typename Container>
void PmergeMe::FordJohnson(Container& container, int left, int right) {
    if (left >= right)
        return;

    Container winners, losers;

    for (int i = left; i + 1 <= right; i += 2) {
        if (container[i] > container[i + 1]) {
            winners.push_back(container[i]);
            losers.push_back(container[i + 1]);
        } else {
            winners.push_back(container[i + 1]);
            losers.push_back(container[i]);
        }
    }

    if ((right - left + 1) % 2 != 0)
        winners.push_back(container[right]);

    FordJohnson(winners, 0, winners.size() - 1);
    InsertLosersToWinners(winners, losers);

    std::copy(winners.begin(), winners.begin() + (right - left + 1), container.begin() + left);
}
