/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:09:54 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/04 16:51:49 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_p(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (game->map->cont[y][x] == 'P' || game->map->cont[y][x] == 'Z')
			{
				game->map->starting.x = x;
				game->map->starting.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	close_window(void *param)
{
	t_game	*game;

	game = param;
	delete_game(game);
	exit(0);
}

void	inject_old(t_game *game)
{
	game->map->old.x = game->map->starting.x;
	game->map->old.y = game->map->starting.y;
}

void	update_position(t_game *game, int new_y, int new_x, char new_tile)
{
	inject_old(game);
	game->map->cont[game->map->starting.y][game->map->starting.x] = '0';
	game->map->starting.y = new_y;
	game->map->starting.x = new_x;
	game->map->cont[new_y][new_x] = new_tile;
}

void	move_away(t_game *game, int new_y, int new_x)
{
	inject_old(game);
	game->map->cont[game->map->starting.y][game->map->starting.x] = 'E';
	game->map->starting.y = new_y;
	game->map->starting.x = new_x;
	game->map->cont[game->map->starting.y][game->map->starting.x] = 'P';
}
