/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_temp_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:31:33 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/28 18:45:17 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (0);
	return (1);
}

//1 means pass
int	loop_temp_map(char **temp_map, t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < ft_strlen(temp_map[i]))
		{
			if (!is_valid_char(temp_map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	loop_cont(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	col;
	unsigned int	count;

	count = 0;
	col = ft_strlen(game->map->cont[0]);
	i = 0;
	while (game->map->cont[i])
	{
		j = 0;
		while (game->map->cont[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	if (count != col * game->map->rows)
		return (0);
	return (1);
}
