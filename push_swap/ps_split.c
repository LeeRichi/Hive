/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:53:21 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/12 19:44:47 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str)
{
	int	i;
	int	am;

	i = 0;
	am = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != '\0' && str[i + 1] != ' ')
		{
			while (str[i] == ' ')
				i++;
			am++;
		}
		i++;
	}
	return (am + 1);
}

int	str_len(char *str)
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
	// ft_printf("am_words: %d\n", *am_words);
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
			while (*str && (*str != ' ')) //  first second third
				str++;
		}
		result[i] = NULL;
		result[0] = NULL;
	}
	return (result);
}
