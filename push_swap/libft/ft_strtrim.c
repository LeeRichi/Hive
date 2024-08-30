/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:04:00 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:44:08 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_matched(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	str_len(char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static int	find_start(char const *s1, char const *set)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (s1[i])
	{
		if (!is_matched(s1[i], set))
			break ;
		i++;
		start++;
	}
	return (start - 1);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	i = str_len(s1);
	end = i - 1;
	while (end >= 0)
	{
		if (!is_matched(s1[end], set))
			break ;
		end--;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	i = find_end(s1, set) - start;
	if (s1 == set || start == str_len(s1) - 1)
		i = 1;
	result = (char *)malloc((i) * sizeof(char));
	if (!result)
		return (NULL);
	if (start == str_len(s1) - 1)
		result[0] = '\0';
	i = 0;
	while (start < find_end(s1, set) - 1)
	{
		result[i] = s1[start + 1];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}
