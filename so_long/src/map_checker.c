/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/07 23:36:55 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//template
//void  flood_fill(char **tab, t_point size, t_point begin)

int	map_checker(t_game *game)
{
	//check the border
	char **temp_map = NULL;
	t_point size;
	t_point begin;
	unsigned int i = 0;
	unsigned int j = 0;
	//run while loop until find the starting point, which is 0
	game->map->cols = ft_strlen(game->map->cont[0]); //7

	// ft_printf("game->map->cols: %d\n", game->map->cols); //7

	// while (game->map->cont[j][i] - '0' != 0 && i < game->map->cols) // 7 //assuming i is not 7+1
	// 	i++;
	// ft_printf("i: %d\n", i);
	// in this case, 0 is not found, go to the next row.
	// if (i > game->map->cols-1)
	// {
	// 	i = 0;
	// 	while (game->map->cont[j][i] - '0' != 0 && i < game->map->cols)
	// 		i++;
	// 	j++;
	// }

	ft_printf("%c\n", game->map->cont[3][2]);

	//find starts
	j = 0;
	while (j < game->map->rows)
	{
		i = 0;
		while (i < game->map->cols)
		{
			if (game->map->cont[j][i] == 'P')
			{
				ft_printf("j: %d\n", j);
				ft_printf("i: %d\n", i);

				ft_printf("true\n");
				game->map->starts = (t_point){j, i};
				break ;
			}
			i++;
		}
		j++;
	}

	ft_printf("j: %d\n", j);
	ft_printf("i: %d\n", i);

	ft_printf("x: %d\n", game->map->starts.x);
	ft_printf("y: %d\n", game->map->starts.y);

	game->map->cont[game->map->starts.x][game->map->starts.y] = '0';

	temp_map = game->map->cont;

	begin = (t_point){game->map->starts.y, game->map->starts.x};

	ft_printf("begin.x: %d\n", begin.x);
	ft_printf("begin.y: %d\n", begin.y);

	size = (t_point){game->map->cols, game->map->rows};

	ft_printf("size.cols: %d\n", game->map->cols);
	ft_printf("size.rows: %d\n", game->map->rows);

	//before
	i = 0;
	while(i < game->map->rows)
	{
		ft_printf("before: %s\n", temp_map[i]);
		i++;
	}

	flood_fill(temp_map, size, begin);

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
		ft_printf("after: %s\n", temp_map[i]);
		i++;
	}

	//temp
	return (1);
}
