/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:28:51 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:44:21 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	total_len(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_memo;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = total_len(s1, s2);
	result_memo = (char *)malloc((i + 1) * sizeof(char));
	if (!result_memo)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result_memo[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result_memo[i + j] = s2[j];
		j++;
	}
	result_memo[i + j] = '\0';
	return (result_memo);
}
