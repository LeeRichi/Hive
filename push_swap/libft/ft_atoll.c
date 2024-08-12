/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:15:24 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/12 15:50:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoll(char *str)
{
	int		flag;
	int		result;
	int		int_buffer;

	flag = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		int_buffer = result;
		result = 10 * result + (*str - 48);
		if (flag > 0 && result / 10 != int_buffer)
			return (-1);
		else if (flag < 0 && result / 10 != int_buffer)
			return (0);
		str++;
	}
	return (result * flag);
}
