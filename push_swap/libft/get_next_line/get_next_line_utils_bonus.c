/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:42:54 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/27 14:51:15 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchar(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *a, char *b)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	len;

	if (!a)
	{
		a = malloc(sizeof(char));
		if (!a)
			return (NULL);
		a[0] = '\0';
	}
	len = ft_strlen(a) + ft_strlen(b);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (ft_free(&a));
	i = -1;
	while (a[++i])
		new_str[i] = a[i];
	j = -1;
	while (b[++j])
		new_str[i + j] = b[j];
	new_str[i + j] = 0;
	free(a);
	return (new_str);
}

char	*substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
