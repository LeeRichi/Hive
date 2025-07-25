#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
		auto it = std::find(container.begin(), container.end(), value);
		if (it == container.end()) {
			throw std::runtime_error("Value not found in the container");
		}
		return it;
}

// Const version:
template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in the container");
    }
    return it;
}
