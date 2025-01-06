/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:03:04 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 23:40:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += printchar(va_arg(args, int));
	else if (specifier == 's')
		count += printstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += printaddress(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += printnbr((long)va_arg(args, int), 10);
	else if (specifier == 'u')
		count += printnbr((long)va_arg(args, unsigned int), 10);
	else if (specifier == 'x')
		count += printnbr((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += printnbr_butx((long)va_arg(args, unsigned int), 16);
	else
		count += printchar(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		result;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			result = print_format(*++format, args);
			if (result == -1)
				return (-1);
			count += result;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			count += 1;
		}
		++format;
	}
	va_end(args);
	return (count);
}
