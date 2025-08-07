#include <algorithm>
#include "PmergeMe.hpp"


// <h1>Trick of using Jacobsthal</h1>
// You insert b5, then b4
// You search in the bounded region before a5
// Because b5 < a5, you know:
// b5 belongs somewhere before a5
// So you never need to look beyond a5
// Search space is 2^(k+1)-1
// Then for b4, the search region shrinks slightly (to a4), but the number of items grows by 1 (because you just inserted b5). So the total comparisons stay optimal.


//to generate Jacobsthal sequence
template <typename Container>
static std::vector<int> Jacobsthal(int n) {
    std::vector<int> sequence;
    int j0 = 0, j1 = 1;

    int next = j1 + 2 * j0;  // j2
    while (next < n) {
        sequence.push_back(next);
        j0 = j1;
        j1 = next;
        next = j1 + 2 * j0;
    }
    return sequence;
}

//second step of the algorithm
template <typename Container>
void insert(Container& main, Container& pend, Container& leftover, size_t unit_size, Container& container) {
    if (main.size() < 2) return;

    size_t unitSize = unit_size;
    if (unitSize == 0 || pend.size() < unitSize)
        return;

    // Track full unit positions in pend (only complete units)
    std::vector<size_t> pendUnits;
    for (size_t i = 0; i + unitSize <= pend.size(); i += unitSize)
        pendUnits.push_back(i); // just the starting index of each pend unit

    // Jacobsthal indices based on number of full units
    std::vector<int> jacob = Jacobsthal<Container>(pendUnits.size());

    std::vector<bool> inserted(pendUnits.size(), false);

    // Insert pend units in Jacobsthal order
    for (int idx : jacob) {
        if (idx < 0 || static_cast<size_t>(idx) >= pendUnits.size())
            continue;

        size_t startIndex = pendUnits[idx];
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
        inserted[idx] = true;
    }

    for (size_t i = 0; i < pendUnits.size(); ++i) {
        if (inserted[i]) continue; //we dont want to loop over already inserted units
        size_t startIndex = pendUnits[i];
        auto unitStart = pend.begin() + startIndex;
        auto unitEnd = unitStart + unitSize;
        int value = *(unitEnd - 1);

        std::vector<int> mainUnitLastElements;
        for (size_t i = 0; i + unitSize <= main.size(); i += unitSize) {
            mainUnitLastElements.push_back(main[i + unitSize - 1]);
        }

        auto insertIt = std::upper_bound(mainUnitLastElements.begin(), mainUnitLastElements.end(), value);
        size_t insertIndex = insertIt - mainUnitLastElements.begin();
        auto pos = main.begin() + insertIndex * unitSize;

        main.insert(pos, unitStart, unitEnd);
    }

    // Insert leftover elements at the end
    main.insert(main.end(), leftover.begin(), leftover.end());

    //put main into cotainer by copy
    container = main;
}

template <typename Container>
void PmergeMe::FordJohnson(Container& container) {
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
    FordJohnson(container);
    unit_size /= 2;

    size_t units = container.size() / unit_size;
    Container main, pend;

    main.insert(main.end(), container.begin(), container.begin() + unit_size); //b1
    main.insert(main.end(), container.begin() + unit_size, container.begin() + 2 * unit_size); //a1

    for (size_t i = 2; i < units; ++i) {
        size_t index = i * unit_size;
        if (i % 2 == 0)
            pend.insert(pend.end(), container.begin() + index, container.begin() + index + unit_size);
        else
            main.insert(main.end(), container.begin() + index, container.begin() + index + unit_size);
    }

    // Handle leftovers (anything beyond full units)
    Container leftover(container.begin() + units * unit_size, container.end());

    //second step
    insert(main, pend, leftover, unit_size, container);
}

//recursive visualization
// unit_size = 1
// → call FordJohnson (unit_size = 2)

//     → call FordJohnson (unit_size = 4)

//         → call FordJohnson (unit_size = 8)

//             → call FordJohnson (unit_size = 16)

//                 → hits base case → return

//             ← continue at unit_size = 8 → insert(...)
//         ← continue at unit_size = 4 → insert(...)
//     ← continue at unit_size = 2 → insert(...)
// ← continue at unit_size = 1 → insert(...)
