/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:34:49 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:45:01 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_extraction(char *str, int *result, int *int_buffer, int flag)
{
	while (*str >= '0' && *str <= '9')
	{
		*int_buffer = *result;
		*result = 10 * *result + (*str - 48);
		if (flag > 0 && *result / 10 != *int_buffer)
			return (-1);
		else if (flag < 0 && *result == -2147483648)
			return (-2147483648);
		else if (flag < 0 && *result / 10 != *int_buffer)
			return (0);
		str++;
	}
	return (*result);
}

int	invalid_sig(int sig)
{
	if (sig == -1 || sig == -2147483648 || sig == 0)
		return (1);
	return (0);
}

int	ft_atoll(char *str)
{
	int		flag;
	int		result;
	int		int_buffer;
	int		extraction_result;

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
	extraction_result = ft_extraction(str, &result, &int_buffer, flag);
	if (invalid_sig(extraction_result))
		return (extraction_result);
	return (result * flag);
}
