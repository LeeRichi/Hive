#include <iostream>
#include "Span.hpp"
#include <numeric>

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

int main()
{
		Span sp = Span(10002);

		int minVal = INT_MAX, maxVal = INT_MIN;

		std::vector<int> randomVec;
		for (int i = 0; i < 10000; ++i)
		{
			int val = rand() % 100000;
			randomVec.push_back(val);
			if (val < minVal) minVal = val;
			if (val > maxVal) maxVal = val;
		}

		try {
			sp.addNumbers(randomVec.begin(), randomVec.end());

			std::cout << "Expected longest span: " << maxVal - minVal << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
}
