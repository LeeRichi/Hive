/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:59:27 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/08 17:02:33 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_and_draw_helper(t_game *game, int wy, int wx, char tile)
{
	if (tile == '1')
		draw_block(game, game->img[W], wy, wx);
	else if (tile == 'P')
		draw_block(game, game->img[P], wy, wx);
	else if (tile == 'C')
		draw_block(game, game->img[C], wy, wx);
	else if (tile == 'E')
	{
		draw_block(game, game->img[G], wy, wx);
		draw_block(game, game->img[E], wy, wx);
	}
	else if (tile == 'Z')
		draw_block(game, game->img[P], wy, wx);
}

static void	check_and_draw(t_game *game, int window_y, int window_x, char tile)
{
	draw_block(game, game->img[G], window_y, window_x);
	check_and_draw_helper(game, window_y, window_x, tile);
}

void	check_block(t_game *game, int y, int x, int is_big_map)
{
	int	window_y;
	int	window_x;
	int	cam_y;
	int	cam_x;

	cam_y = 0;
	cam_x = 0;
	if (is_big_map)
	{
		cam_y = game->camera_pos.y;
		cam_x = game->camera_pos.x;
	}
	window_y = (y - cam_y) * game->map->block_len;
	window_x = (x - cam_x) * game->map->block_len;
	check_and_draw(game, window_y, window_x, game->map->cont[y][x]);
}
