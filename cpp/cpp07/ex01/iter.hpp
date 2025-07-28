#pragma once
#include <cstddef> // for size_t

// template <class A, class T_Func>
// void iter(A *array, size_t length, T_Func func)
// {
//     for (size_t i = 0; i < length; i++)
//         (func)(array[i]);
// }

template <typename A>
void iter(A *array, size_t length, void(*func)(const A &))
{
	for (size_t i = 0; i < length; i++)
		(func)(array[i]);
}
