#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char *argv[])
{
	int test;
	// char *test_char;

	// test = 10;
	// test_char = "hi, noob";

	// //basics
	// ft_printf("%c\n", 'h');
	// ft_printf("%s\n", "ssh");
	// ft_printf("%d\n", 22);
	// ft_printf("%d\n", 244);
	// ft_printf("%d\n", INT_MAX);
	// ft_printf("my: %c %c %c \n", '0', 0, '1');
	// printf("og: %c %c %c \n", '0', 0, '1');

	// ft_printf("count: %d\n", ft_printf("my: %c %c %c \n", '0', 2, '1'));
	// printf("count: %d\n", ft_printf("og: %c %c %c \n", '0', 2, '1'));

	// ft_printf("%p \n", -1);
	// printf("%p \n", -1);

	// ft_printf("count: %d\n", ft_printf("%p \n", -100));
	// printf("count: %d\n", printf("%p \n", -100));

	//hanlding max values
	// ft_printf("My: %p %p \n", LONG_MIN, LONG_MAX);
	// printf("OG: %p %p ", LONG_MIN, LONG_MAX);

	// printf("My return value: %d\n", ft_printf("My: %p %p \n", LONG_MIN, LONG_MAX));
	// printf("OG return value: %d\n", printf("OG: %p %p \n", LONG_MIN, LONG_MAX));

	// ft_printf("My: %p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf("OG: %p %p ", ULONG_MAX, -ULONG_MAX);

	// ft_printf("MY: %p, %p\n", ULONG_MAX, -ULONG_MAX);
	// printf("OG: %p, %p\n", ULONG_MAX, -ULONG_MAX);

	// ft_printf("My: -ULONG_MAX OG: %p, %d\n", -ULONG_MAX, -ULONG_MAX);
	
	// printf("%d\n", ft_printf("MY: %p, %p\n", ULONG_MAX, -ULONG_MAX));
	// printf("%d\n", printf("OG: %p, %p\n", ULONG_MAX, -ULONG_MAX));

	// printf("test MY:%d\n", ft_printf("MY: %p\n", ULONG_MAX));
	// printf("test OG:%d\n", printf("OG: %p\n", ULONG_MAX));

	// printf("%d\n", ft_printf("MY: %p\n", -ULONG_MAX));
	// printf("%d\n", printf("OG: %p\n", -ULONG_MAX));

	printf("\nRich pppp: %d\n", ft_printf("RI Address: %p\n", (void *)-14523));
	printf("\nOG pppprinf: %d\n", printf("OG Address: %p\n", (void *)-14523));

	// ft_printf("My: %d \n", LONG_MIN);
	// printf("OG: %d \n", LONG_MIN);

	// //
	// ft_printf("mine: %X\n", 233);
	// printf("og: %X\n", 233);

	// //(null)
	// ft_printf("Mine: %s\n", NULL);
	// printf("OG: %s\n", NULL);

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


	// printf("----tricks----\n");
	// printf("OG return value: %d\n", printf("%")); //0

	// ft_printf("My return value: %d\n", ft_printf("%")); //0 ??
	// ft_printf("%");
	return (0);
}