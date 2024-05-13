/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:04:53 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/13 15:19:23 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int ft_printf(const char *, ...);
int	printchar(int c);
int	printstr(char *s);
int printnbr(long n, int base);
int printnbr_butX(long n, int base);
int printaddress(unsigned long something);

# endif