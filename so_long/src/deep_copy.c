/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:59:10 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 00:02:45 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**deep_copy(char **source, unsigned int rows, unsigned int cols)
{
	char			**temp;
	unsigned int	i;

	temp = malloc(sizeof(char *) * rows);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		temp[i] = malloc(sizeof(char) * (cols + 1));
		if (!temp[i])
		{
			while (i-- > 0)
				free(temp[i]);
			free(temp);
			return (NULL);
		}
		ft_strlcpy(temp[i], source[i], cols + 1);
		i++;
	}
	return (temp);
}

void	free_copy(char **temp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(temp[i++]);
	free(temp);
}
