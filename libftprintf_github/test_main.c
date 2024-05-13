#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char *argv[])
{
	int test;
	char *test_char;

	test = 10;
	test_char = "hi, noob";

	// ft_printf("%c", 'h');
	// ft_printf("%s", "ssh");
	// ft_printf("%d", 22);
	// ft_printf("%d\n", 244);
	// ft_printf("%d\n", INT_MAX);
	// ft_printf("mine: %X\n", 233);
	// printf("og: %X\n", 233);


	// ft_printf("mine: %X\n", 23315161);
	// printf("og: %X\n", 23315161);

    //address
	ft_printf("Mine: %p\n", test);
	printf("og: %p\n", test);

	ft_printf("Mine: %p\n", test_char);
	printf("og: %p\n", test_char);

	//ft_printf("an int: %d and a char: %c", 1, 'a');
	// ft_printf("My: %c, %d\n", 1, '1');
	// printf("OG: %c, %d", 1, '1');
	return (0);
}