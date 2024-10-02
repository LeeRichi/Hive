/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_packs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:10:29 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/02 19:16:46 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_check(t_game *game, char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)game->map->rows)
	{
		j = 0;
		while (j < (int)game->map->cols)
		{
			if (temp[i][j] == 'C' || temp[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
