/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/06 13:23:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//template
//void  flood_fill(char **tab, t_point size, t_point begin)


int	map_checker(t_game *game)
{
	//check the border

	t_map **temp_map;
	t_point size;
	t_point begin;
	unsigned int i;


	//run while loop until find the starting point, which is 0
	i = 0;
	while (game->map->cont[i][0] != 0 && i < game->map->cols)
		i++;
	begin = (t_point){i, 0};

	size = (t_point){game->map->cols, game->map->rows};

	temp_map = flood_fill(game->map, size, begin);
}
