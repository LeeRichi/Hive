/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:03:04 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/13 12:56:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(char specifier, va_list args)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += printchar(va_arg(args, int));
	else if (specifier == 's')
		count += printstr(va_arg(args, char *));
	else if (specifier == 'd')
		count += printnbr((long)va_arg(args, int), 10);
	else if (specifier == 'x')
		count += printnbr((long)va_arg(args, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	count;

	va_start(args, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else 
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
