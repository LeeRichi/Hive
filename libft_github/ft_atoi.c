/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:20:21 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/07 15:26:03 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	int			result;
	long		long_buffer;

	flag = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	long_buffer = 0;
	while (*str >= '0' && *str <= '9')
	{
		long_buffer = 10 * long_buffer + (*str - 48);
		if (flag > 0 && long_buffer < 0)
			return (-1);
		else if (flag < 0 && long_buffer < 0)
			return (0);
		str++;
	}
	result = long_buffer * flag;
	return (result);
}
