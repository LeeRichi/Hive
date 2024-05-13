#include "ft_printf.h"

#include <stdio.h>

int count = 0;

int	printchar(int c)
{
	if (!c)
		return (-1);
	return (write(1, &c, 1));
}

int	printstr(char *s)
{
	if (!s)
		return (printstr("(null)"));
	while (*s)
	{
		printchar((int)*s);
		count++;
		++s;
	}
	return (count);
}

int printnbr(long n, int base)
{
	char *symbols;
	
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return(printnbr(-n, base) + 1);
	}
	else if (n < base)
		return (printchar(symbols[n]));
	else 
	{
		count = printnbr(n / base, base);
		return (count + printnbr(n % base, base));
	}	
}


// int printnbr(long *count, long n)
// {
// 	char new_n;

// 	if (n < 0)
// 	{
// 		(*count)++;
// 		if (write(1, "-", 1) == -1)
// 			return (-1);
// 		n = -n;
// 	}
// 	while (n >= 10)
// 	{
// 		if (printnbr(count, n / 10) == -1)
// 			return (-1);
// 	}
// 	new_n = n % 10 + '\0';
// 	(*count)++;
// 	if (write(1, &new_n, 1) == -1)
// 		return (-1);
// 	return (*count);
// }