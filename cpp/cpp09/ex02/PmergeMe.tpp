#include <algorithm>
#include "PmergeMe.hpp"

// template <typename Container>
// static std::vector<int> Jacobsthal(int n) {
// 	std::vector<int> sequence;
// 	sequence.push_back(0);  // J0
// 	if (n == 0) return sequence;
// 	sequence.push_back(1);  // J1

// 	int i = 2;
// 	while (true) {
// 			int next = sequence[i - 1] + 2 * sequence[i - 2];
// 			if (next >= n)
// 					break;
// 			if (next != sequence.back())
// 				sequence.push_back(next);
// 			i++;
// 	}
// 	return sequence;
// }


//temp
template <typename Container>
void printContainer(const Container& container) {
    for (const auto& elem : container) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

template <typename Container>
static std::vector<int> Jacobsthal(int n) {
    // std::cout << "n: " << n << std::endl;
    std::vector<int> sequence;
    int j0 = 0, j1 = 1;

    int next = j1 + 2 * j0;  // J2
    while (next < n) {
        sequence.push_back(next);
        j0 = j1;
        j1 = next;
        next = j1 + 2 * j0;
    }

    // std::cout << "test: " << std::endl;
    // printContainer(sequence);
    return sequence;
}

// int PmergeMe::Jacobsthal(int k)
// {
//     return round((pow(2, k + 1) + pow(-1, k)) / 3);
// }


template <typename Container>
void insert(Container& main, Container& pend, bool isOdd, int odd, Container& leftover, size_t unit_size, Container& container) {
    if (main.size() < 2) return;

    // const size_t unitSize = main.size() / 2;
    size_t unitSize = unit_size;
    if (unitSize == 0 || pend.size() < unitSize)
        return;

    // std::cout << "DEBUG: pend.size(): " << pend.size() << ", unitSize: " << unitSize << '\n';

    // Track full unit positions in pend (only complete units)
    std::vector<size_t> pendUnits;
    for (size_t i = 0; i + unitSize <= pend.size(); i += unitSize)
        pendUnits.push_back(i); // just the starting index of each pend unit

    // std::cout << "Pend units:\n";
    // std::cout << "Pend units size: " << pendUnits.size() << std::endl;
    // for (const auto& startIndex : pendUnits) {
    //     size_t endIndex = startIndex + unitSize;
    //     for (size_t i = startIndex; i < endIndex; ++i) {
    //         std::cout << pend[i] << ' ';
    //     }
    //     std::cout << '\n';
    // }


    // Jacobsthal indices based on number of full units
    std::vector<int> jacob = Jacobsthal<Container>(pendUnits.size());

    // int jacob = Jacobsthal(pendUnits.size());
    // std::cout << "Jacobsthal indices: " << jacob << std::endl;
    // std::cout << "Jacobsthal indices: ";
    // printContainer(jacob);
    std::vector<bool> inserted(pendUnits.size(), false);

    // Insert pend units in Jacobsthal order
    for (int idx : jacob) {
        if (idx < 0 || static_cast<size_t>(idx) >= pendUnits.size())
            continue;

        size_t startIndex = pendUnits[idx];
        // std::cout << "idx: " << idx << std::endl;
        auto unitStart = pend.begin() + startIndex;
        auto unitEnd = unitStart + unitSize;

        int value = *(unitEnd - 1);  // last element of unit to insert

        // Build a vector of last elements of each unit in main
        std::vector<int> mainUnitLastElements;
        for (size_t i = 0; i + unitSize <= main.size(); i += unitSize) {
            mainUnitLastElements.push_back(main[i + unitSize - 1]);
        }

        // Find insertion index in main units based on last elements
        auto insertIt = std::upper_bound(mainUnitLastElements.begin(), mainUnitLastElements.end(), value);

        // Calculate the position in main iterator terms
        size_t insertIndex = insertIt - mainUnitLastElements.begin();
        auto pos = main.begin() + insertIndex * unitSize;

        main.insert(pos, unitStart, unitEnd);
        // std::cout << "Inserted unit at index " << idx << ": ";
        // printContainer(main);
        inserted[idx] = true;
    }


    // std::cout << "After Jacobsthal insertion:\n";
    // printContainer(main);

    // Insert any remaining pend units
    // std::cout << " pendUnits.size(): " << pendUnits.size() << std::endl;

    for (size_t i = 0; i < pendUnits.size(); ++i) {
        if (inserted[i]) continue; //we dont want to loop over already inserted units
        // std::cout << "Inserting remaining pend unit at index " << i << std::endl;
        size_t startIndex = pendUnits[i];
        // std::cout << "startIndex: " << startIndex << std::endl;
        auto unitStart = pend.begin() + startIndex;
        auto unitEnd = unitStart + unitSize;
        // std::cout << "unitStart: " << *unitStart << ", unitEnd: " << *(unitEnd - 1) << std::endl;
        int value = *(unitEnd - 1);

        // std::cout << "value: " << value << std::endl;

        std::vector<int> mainUnitLastElements;
        for (size_t i = 0; i + unitSize <= main.size(); i += unitSize) {
            mainUnitLastElements.push_back(main[i + unitSize - 1]);
        }

        auto insertIt = std::upper_bound(mainUnitLastElements.begin(), mainUnitLastElements.end(), value);
        size_t insertIndex = insertIt - mainUnitLastElements.begin();
        auto pos = main.begin() + insertIndex * unitSize;

        main.insert(pos, unitStart, unitEnd);

        //insert everything to replace our container
        // std::cout << "Inserted remaining pend unit at index " << i << ": ";
        // printContainer(main);
    }

    // std::cout << "After remaining pend insertion:\n";
    // printContainer(main);

    (void)odd;
    // Handle the odd singleton if present
    if (isOdd) {
        // std::cout << "Inserting odd element: " << odd << std::endl;
        // auto pos = std::upper_bound(main.begin(), main.end(), odd);
        // main.insert(pos, odd);
        // std::cout << "FUCK: \n";
        // printContainer(main);
    }

    // Insert leftover elements at the end
    main.insert(main.end(), leftover.begin(), leftover.end());
    // std::cout << "After insertion:\n";
    // printContainer(main);

    //put main into cotainer by copy
    container = main;
}

template <typename Container>
void PmergeMe::FordJohnson(Container& container, int left, int right) {
    (void)unit_size;
    (void)left;
    (void)right;
    (void)container;

    if (unit_size == 0 || container.size() / unit_size < 2)
        return;

    for (size_t i = 0; i <= container.size() - unit_size * 2; i += unit_size * 2)
    {
        if (container[i + unit_size - 1] > container[i + unit_size * 2 - 1])
        {
            for (size_t j = 0; j < unit_size; j++)
            {
                std::swap(container[i + j], container[i + unit_size + j]);
            }
        }
    }

    unit_size *= 2;
    FordJohnson(container, left, right);
    unit_size /= 2;

    // std::cout << "------------------------\n";
    // std::cout << "unit_size: " << unit_size << std::endl;

    //test print
    // printContainer(container);
    // std::cout << "Container size: " << container.size() << std::endl;
    size_t units = container.size() / unit_size;
    // std::cout << "units: " << units << std::endl;
    bool isOdd = units % 2;
    Container main, pend;

    main.insert(main.end(), container.begin(), container.begin() + unit_size);
    main.insert(main.end(),
            container.begin() + unit_size,
            container.begin() + 2 * unit_size);

    // std::cout << "earliy main: \n";
    // printContainer(main);

    // Alternate the rest between pend and main (insert whole units)
    // for (size_t i = 2; i < units - isOdd; ++i) {
    for (size_t i = 2; i < units; ++i) {
        size_t index = i * unit_size;
        if (i % 2 == 0)
            pend.insert(pend.end(), container.begin() + index, container.begin() + index + unit_size);
        else
            main.insert(main.end(), container.begin() + index, container.begin() + index + unit_size);
    }


    //insert the last element if odd
    // if (isOdd) {
    //     main.---
    // std::cout << "main: \n";
    // printContainer(main);
    // std::cout << "pend: \n";
    // printContainer(pend);

    int odd = 0;
    if (isOdd)
        odd = container[units * unit_size - 1];

    // Optionally handle leftovers (anything beyond full units)
    Container leftover(container.begin() + units * unit_size, container.end());

    // std::cout << "leftover: \n";
    // printContainer(leftover);

    insert(main, pend, isOdd, odd, leftover, unit_size, container);
}
