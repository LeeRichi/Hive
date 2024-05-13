#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char *argv[])
{
	// int test;
	// char *test_char;

	// test = 10;
	// test_char = "hi, noob";

	// //basics
	// ft_printf("%c\n", 'h');
	// ft_printf("%s\n", "ssh");
	// ft_printf("%d\n", 22);
	// ft_printf("%d\n", 244);
	// ft_printf("%d\n", INT_MAX);

	// //X
	// ft_printf("mine: %X\n", 233);
	// printf("og: %X\n", 233);

	// //(null)
	// ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);

	// //multiples
	// ft_printf("mine: 1: %X, 2: %x, 3. %d, 4, %u\n", 233, 233, 233, 233);
	// printf("mine: 1: %X, 2: %x, 3. %d, 4, %u\n", 233, 233, 233, 233);

    // //address
	// ft_printf("Mine: %p\n", test);
	// printf("og: %p\n", test);

	// ft_printf("Mine: %p\n", test_char);
	// printf("og: %p\n", test_char);

	// //tricks
	// printf("ticky parts\n");
	// ft_printf("Mine: %%\n", test_char);
	// printf("Mine: %", test_char);

	printf("OG return value: %d\n", printf("%"));

	ft_printf("My return value: %d\n", ft_printf("%"));
	ft_printf("%");
	return (0);
}