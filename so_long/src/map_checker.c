/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/07 20:14:58 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//template
//void  flood_fill(char **tab, t_point size, t_point begin)

int	map_checker(t_game *game)
{
	//check the border
	// t_map **temp_map;
	t_point size;
	t_point begin;
	unsigned int i;
	unsigned int j;
	//run while loop until find the starting point, which is 0
	i = 0;
	j = 0;
	game->map->cols = ft_strlen(game->map->cont[0]); //7

	ft_printf("game->map->cols: %d\n", game->map->cols); //7

	while (game->map->cont[j][i] - '0' != 0 && i < game->map->cols) // 7 //assuming i is not 7+1
		i++;
	ft_printf("i: %d\n", i);
	// in this case, 0 is not found, go to the next row.
	if (i > game->map->cols-1)
	{
		j++;
		i = 0;
		while (game->map->cont[j][i] - '0' != 0 && i < game->map->cols)
			i++;
		j++;
	}
	begin = (t_point){j, i};

	size = (t_point){game->map->cols, game->map->rows};



	flood_fill(game->map->cont, size, begin);

	// i = 0;
	// while(i < game->map->cols)
	// {
	// 	j = 0;
	// 	while(j < game->map->rows)
	// 	{
	// 		ft_printf("%s")
	// 	}	j++;
	// 	i++;
	// }

	//print
	i = 0;
	while(i < game->map->rows)
	{
		ft_printf("%s\n", game->map->cont[i]);
		i++;
	}

	//temp
	return (1);
}
