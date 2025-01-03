/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:52 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/05 22:25:22 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	gnl_strlen(char *s)
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

char	*gnl_strjoin(char *a, char *b)
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
	len = gnl_strlen(a) + gnl_strlen(b);
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
	if (gnl_strlen(s) - start < len)
		len = gnl_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < gnl_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
