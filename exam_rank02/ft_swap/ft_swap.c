#include <libc.h>

void    ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


// int main(void)
// {
//     int x = 1; // Initialize an integer
//     int y = 2; // Initialize another integer

//     int *a = &x; // Point a to x
//     int *b = &y; // Point b to y

//     printf("Before swap: a = %d, b = %d\n", *a, *b); // Print values before swap

//     ft_swap(a, b); // Swap the values

//     printf("After swap: a = %d, b = %d\n", *a, *b); // Print values after swap

//     return 0;
// }
