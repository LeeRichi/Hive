/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:53:21 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 17:54:04 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str)
{
	int	i;
	int	am;

	i = 0;
	am = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			am++;
		i++;
	}
	return (am + 1);
}

static int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*malloc_a_word(char *str)
{
	int		i;
	int		len;
	char	*result;

	len = str_len(str);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ps_split(char *str, int *am_words)
{
	char	**result;
	int		i;

	*am_words = count_word(str);
	result = (char **)malloc((*am_words + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 1;
	while (*str)
	{
		while (*str && (*str == ' '))
			str++;
		if (*str && (*str != ' '))
		{
			result[i] = malloc_a_word(str);
			i++;
			while (*str && (*str != ' '))
				str++;
		}
		result[i] = NULL;
	}
	return (result);
}
