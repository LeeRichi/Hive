/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:04:53 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/20 11:29:40 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printchar(char c);
int	printstr(char *s);
int	printnbr(long n, int base);
int	printnbr_butx(long n, int base);
int	printnbr_foraddress(unsigned long n, int base);
int	printaddress(unsigned long something);

#endif
