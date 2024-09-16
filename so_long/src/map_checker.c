/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/16 12:40:16 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char **deep_copy(char **source, unsigned int rows, unsigned int cols)
{
	char **temp;
	unsigned int i;

	temp = malloc(sizeof(char *) * rows);
	if (!temp)
		return (NULL);

	i = 0;
	while (i < rows)
	{
		temp[i] = malloc(sizeof(char) * (cols + 1));
		if (!temp[i])
		{
			while(i-- > 0)
				free(temp[i]);
			free(temp);
			return (NULL);
		}
		ft_strlcpy(temp[i], source[i], cols + 1);
		i++;
	}
	return (temp);
}

static void free_copy(char **temp, int rows)
{
	int i;

	i = 0;
	while(i < rows)
		free(temp[i++]);
	free(temp);
}

// look for char c
int rich_check_c(char **map, t_point size, char c)
{
	int i = 0;
	int j = 0;

	int collectables;

	collectables = 0;
	j = 0;
	while (j < size.y)
	{
		// if (collectables > 0 && c == 'E')
		// 	return (1);
		i = 0;
		while (i < size.x)
		{
			if (map[j][i] == c)
				collectables++;
			i++;
		}
		j++;
	}
	// if (collectables > 0 && c == 'C')
	if (collectables > 0)
		return (collectables);
	return (0);
}

static int	rich_check_border(char **map, t_point size)
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
	char **temp_map;
	t_point size;
	t_point begin;
	// unsigned int i = 0;
	// unsigned int j = 0;
	game->map->cols = ft_strlen(game->map->cont[0]);
	if (game->map->cols == game->map->rows)
		show_error(game, "Map must be rectangular, invalid map.\n");
	// game->map->starting = (t_point){-1, -1};

	size = (t_point){game->map->cols, game->map->rows};

	//find starting for flood
	// j = 0;
	// while (j < game->map->rows)
	// {
	// 	i = 0;
	// 	while (i < game->map->cols)
	// 	{
	// 		if (game->map->cont[j][i] == 'P')
	// 		{
	// 			game->map->starting = (t_point){j, i};
	// 			break ;
	// 		}
	// 		i++;
	// 	}
	// 	j++;
	// }

	temp_map = deep_copy(game->map->cont, game->map->rows, game->map->cols);
	if (!temp_map)
    {
		show_error(game, "Failed to create temp map\n");
        return (0);
    }
	if (rich_check_c(temp_map, size, 'E') != 1 || rich_check_c(temp_map, size, 'P') != 1)
		show_error(game, "Exit or Player is not equal to 1, invalid map.\n");
	if (!rich_check_border(temp_map, size))
	{
		show_error(game, "border is invalid.\n");
		free_copy(temp_map, game->map->rows);
		return (0);
	}
	find_P(game);
	// if (game->map->starting.x == -1 && game->map->starting.y == -1)
	// 	show_error(game, "Can't find P for starting point of flood.\n");

	//starting point for flood
	temp_map[game->map->starting.x][game->map->starting.y] = '0';
	begin = (t_point){game->map->starting.y, game->map->starting.x};
	game->map->collectibles = rich_check_c(temp_map, size, 'C');

	rich_flood_fill(temp_map, size, begin);

	//these lines can be deleted later
	// if (!(rich_check_c(temp_map, size, 'E') && rich_check_c(temp_map, size, 'C'))) //means possible to collect every Cs and reach E //map is valid
	// 	ft_printf("map is valid.\n");

	free_copy(temp_map, game->map->rows);

	return (1);
}
