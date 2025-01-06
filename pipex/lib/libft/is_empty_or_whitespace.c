/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_or_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:26:49 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 15:46:41 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_empty_or_whitespace(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_space((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
