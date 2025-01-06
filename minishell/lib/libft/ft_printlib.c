/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:56:20 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 23:37:02 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printnbr(long n, int base)
{
	char	*symbols;
	int		count;
	int		result;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		result = printnbr(-n, base);
		if (result == -1)
			return (result);
		return (result + 1);
	}
	else if (n < base)
		return (count + printchar(symbols[n]));
	else
	{
		count = printnbr(n / base, base);
		if (count == -1)
			return (-1);
		return (count + printnbr(n % base, base));
	}
}

int	printnbr_butx(long n, int base)
{
	char	*symbols;
	int		count;
	int		result;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		result = printnbr_butx(-n, base);
		if (result == -1)
			return (result);
		return (result + 1);
	}
	else if (n < base)
		return (count + printchar(symbols[n]));
	else
	{
		count = printnbr_butx(n / base, base);
		if (count == -1)
			return (-1);
		return (count + printnbr_butx(n % base, base));
	}
}

int	printnbr_foraddress(unsigned long n, int base)
{
	char	*symbols;
	int		count;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < (unsigned long)base)
		return (printchar(symbols[n]));
	else
	{
		count = printnbr_foraddress(n / base, base);
		return (count + printnbr_foraddress(n % base, base));
	}
}

int	printaddress(unsigned long something)
{
	int	count;

	count = 0;
	if ((long)(something * -1) == LONG_MIN)
	{
		if (write(1, "0x8000000000000000", 18) == -1)
			return (-1);
		return (18);
	}
	if ((unsigned long)(something) == ULONG_MAX)
	{
		if (write(1, "0xfffffffffffffffff", 18) == -1)
			return (-1);
		return (18);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = printnbr_foraddress((long)something, 16);
	if (count == -1)
		return (-1);
	return (count + 2);
}
