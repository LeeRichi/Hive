/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:06:03 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:44:24 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	memory = (char *)malloc(len * sizeof(char) + 1);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < len)
	{
		memory[i] = s1[i];
		i++;
	}
	memory[i] = '\0';
	return ((char *)memory);
}
