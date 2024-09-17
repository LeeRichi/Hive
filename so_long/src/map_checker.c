/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:34:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 10:18:50 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// look for char c
static int	rich_check_c(char **map, t_point size, char c)
{
	int	i;
	int	j;
	int	collectables;

	collectables = 0;
	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (map[j][i] == c)
				collectables++;
			i++;
		}
		j++;
	}
	if (collectables > 0)
		return (collectables);
	return (0);
}

static int	rich_check_border(char **map, t_point size)
{
	int	i;

	i = 0;
	while (i < size.x)
	{
		if (map[0][i] != '1' || map[size.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < size.y)
	{
		if (map[i][0] != '1' || map[i][size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_eqaul_to_one(char **temp_map, t_point size)
{
	if (rich_check_c(temp_map, size, 'E') != 1)
		return (0);
	if (rich_check_c(temp_map, size, 'P') != 1)
		return (0);
	return (1);
}

static void	values_injection(t_game *game, char **temp_map, t_point size)
{
	int	x;
	int	y;

	x = game->map->starting.x;
	y = game->map->starting.y;
	find_p(game);
	temp_map[game->map->starting.y][game->map->starting.x] = '0';
	game->map->coins = rich_check_c(temp_map, size, 'C');
	game->map->flood_begin = (t_point){y, x};
}

int	map_checker(t_game *game)
{
	char	**temp_map;
	t_point	size;

	game->map->cols = ft_strlen(game->map->cont[0]);
	if (game->map->cols == game->map->rows)
		show_error(game, "Map must be rectangular, invalid map.\n");
	size = (t_point){game->map->cols, game->map->rows};
	temp_map = deep_copy(game->map->cont, game->map->rows, game->map->cols);
	if (!temp_map)
	{
		show_error(game, "Failed to create temp map\n");
		return (0);
	}
	if (!is_eqaul_to_one(temp_map, size))
		show_error(game, "Exit or Player is not equal to 1, invalid map.\n");
	if (!rich_check_border(temp_map, size))
	{
		show_error(game, "border is invalid.\n");
		free_copy(temp_map, game->map->rows);
		return (0);
	}
	values_injection(game, temp_map, size);
	rich_flood_fill(temp_map, size, game->map->flood_begin);
	free_copy(temp_map, game->map->rows);
	return (1);
}
