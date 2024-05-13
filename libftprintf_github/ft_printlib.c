/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:56:20 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/13 15:24:23 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int printnbr_butX(long n, int base)
{
	char *symbols;
	
	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return(printnbr_butX(-n, base) + 1);
	}
	else if (n < base)
		return (printchar(symbols[n]));
	else 
	{
		count = printnbr_butX(n / base, base);
		return (count + printnbr_butX(n % base, base));
	}	
}

int printaddress(unsigned long something)
{
	if (write(1, "0x", 2 ) == -1)
		return (-1);
	if (printnbr((long)something, 16) == -1)
		return (-1);
	return (count + 2);
}
