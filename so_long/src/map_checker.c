/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/09 10:31:19 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//look for char c
int	rich_check_c(char **map, t_point size, char c)
{
	int i = 0;
	int j = 0;

	j = 0;
	while(j < size.y)
	{
		i = 0;
		while(i < size.x)
		{
			if(map[j][i] == c)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	rich_check_border(char **map, t_point size)
{
	int i;

	//check first row and the last row
	i = 0;
	while (i < size.x)
	{
		if(map[0][i] != '1' || map[size.y - 1][i] != '1')
			return (0);
		i++;
	}

	//check first col and the last col
	i = 0;
	while (i < size.y)
	{
		if(map[i][0] != '1' || map[i][size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	char **temp_map = NULL;
	t_point size;
	t_point begin;
	unsigned int i = 0;
	unsigned int j = 0;
	game->map->cols = ft_strlen(game->map->cont[0]);
	game->map->starts = (t_point){-1, -1};

	//find starts
	j = 0;
	while (j < game->map->rows)
	{
		i = 0;
		while (i < game->map->cols)
		{
			if (game->map->cont[j][i] == 'P')
			{
				game->map->starts = (t_point){j, i};
				break ;
			}
			i++;
		}
		j++;
	}
	if (game->map->starts.x == -1 && game->map->starts.y == -1)
	{
		printf("Can't find P\n");
		return (0);
	}

	game->map->cont[game->map->starts.x][game->map->starts.y] = '0';
	temp_map = game->map->cont;
	begin = (t_point){game->map->starts.y, game->map->starts.x};
	size = (t_point){game->map->cols, game->map->rows};
	if (!rich_check_border(temp_map, size))
	{
		ft_printf("border is invalid\n");
		return (0);
	}

	// ft_printf("size.cols: %d\n", game->map->cols);
	// ft_printf("size.rows: %d\n", game->map->rows);

	//temp
	//before
	i = 0;
	while(i < game->map->rows)
	{
		ft_printf("before calling rich_flood_fill: %s\n", temp_map[i]);
		i++;
	}

	rich_flood_fill(temp_map, size, begin);

	if (rich_check_c(temp_map, size, 'E') && rich_check_c(temp_map, size, 'C')) //means possible to collect every Cs and reach E //map is valid
		ft_printf("map is valid.\n");

	// print
	i = 0;
	while(i < game->map->rows)
	{
		ft_printf("after: %s\n", temp_map[i]);
		i++;
	}

	return (1);
}
