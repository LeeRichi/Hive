/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:55:22 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:44:07 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_extra_lenth(char const *s, unsigned int start)
{
	char			*temp;
	unsigned int	i;

	temp = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[start] != '\0')
	{
		temp[i++] = s[start++];
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		return (ft_extra_lenth(s, start));
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		new_str[i++] = s[start++];
	new_str[i] = 0;
	return (new_str);
}
