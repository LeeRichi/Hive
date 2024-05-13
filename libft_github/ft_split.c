/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:05:31 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/07 19:46:38 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*word_dup(char const **str, char sep)
{
	char		*word;
	const char	*temp;
	int			str_len;

	str_len = 0;
	temp = *str;
	while (*temp)
	{
		if (*temp == sep)
			break ;
		str_len++;
		temp++;
	}
	word = ft_substr(*str, 0, str_len);
	if (!word)
		return (NULL);
	while (sep && *temp == sep)
		temp++;
	*str = temp;
	return (word);
}

static char	**clear_array(char **array, int j)
{
	while (j >= 0)
		free(array[j--]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	int				i;
	int				amount_of_strings;

	if (!s)
		return (NULL);
	amount_of_strings = ft_countword(s, c);
	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (i < amount_of_strings)
	{
		result[i] = word_dup(&s, c);
		if (!result[i])
			return (clear_array(result, i - 1));
		i++;
	}
	result[i] = NULL;
	return (result);
}
