/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:04:53 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/16 14:19:44 by chlee2           ###   ########.fr       */
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