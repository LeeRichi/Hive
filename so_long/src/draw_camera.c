/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:41:54 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/08 16:59:19 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//wy = window_y, wx = window_x
void	draw_block(t_game *game, mlx_image_t *img, int wy, int wx)
{
	if (mlx_image_to_window(game->disp.mlx, img, wx, wy) < 0)
		show_error(game, "mlx_image_to_window failed.");
}

// update the window's bound
void	update_camera(t_game *game)
{
	int	visible_width;
	int	mid_position;

	mid_position = game->map->window_width / BLOCK_SIZE / 2;
	visible_width = game->map->window_width / game->map->block_len;
	game->camera_pos.y = game->map->starting.y - visible_width / 2;
	game->camera_pos.x = game->map->starting.x - visible_width / 2;
	if (game->map->cols > 25 || game->map->rows > 25)
	{
		if (game->map->starting.x < mid_position)
			game->camera_pos.x = 0;
		if (game->map->starting.y < mid_position)
			game->camera_pos.y = 0;
	}
	else
	{
		if (game->camera_pos.x < (int)game->map->cols)
			game->camera_pos.x = 0;
		if (game->camera_pos.y < (int)game->map->rows)
			game->camera_pos.y = 0;
	}
	if (game->camera_pos.x > (int)game->map->cols - visible_width)
		game->camera_pos.x = (int)game->map->cols - visible_width;
	if (game->camera_pos.y > (int)game->map->rows - visible_width)
		game->camera_pos.y = (int)game->map->rows - visible_width;
}

//only update two blocks, not whole map nor whole window
void	update_player(t_game *game)
{
	if (game->map->cols > 25 || game->map->rows > 25)
	{
		check_block(game, game->map->starting.y, game->map->starting.x, 1);
		check_block(game, game->map->old.y, game->map->old.x, 1);
	}
	else
	{
		check_block(game, game->map->starting.y, game->map->starting.x, 0);
		check_block(game, game->map->old.y, game->map->old.x, 0);
	}
}

// Draw only the visible portion of the map (within the camera view)
//vw = visible width, vh = visible_height //to solve "line too long"
void	draw_camera(t_game *game)
{
	int	y;
	int	x;
	int	vw;
	int	vh;

	vw = game->disp.width / game->map->block_len;
	vh = game->disp.height / game->map->block_len;
	update_camera(game);
	y = game->camera_pos.y;
	while (y < game->camera_pos.y + vh && y < (int)game->map->rows)
	{
		x = game->camera_pos.x;
		while (x < game->camera_pos.x + vw && x < (int)game->map->cols)
		{
			if (game->map->cols > 25 || game->map->rows > 25)
				check_block(game, y, x, 1);
			else
				check_block(game, y, x, 0);
			x++;
		}
		y++;
	}
}
