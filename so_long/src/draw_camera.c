/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:41:54 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/30 16:02:35 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//wy = window_y, wx = window_x
static void	draw_block(t_game *game, mlx_image_t *img, int wy, int wx)
{
	if (mlx_image_to_window(game->disp.mlx, img, wx, wy) < 0)
		show_error(game, "mlx_image_to_window failed.");
}

// static void	check_block(t_game *game, int y, int x, int cam_y, int cam_x)
static void	check_block(t_game *game, int y, int x, int is_big_map)
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
	draw_block(game, game->img[G], window_y, window_x);
	if (game->map->cont[y][x] == '1')
		draw_block(game, game->img[W], window_y, window_x);
	else if (game->map->cont[y][x] == 'P')
		draw_block(game, game->img[P], window_y, window_x);
	else if (game->map->cont[y][x] == 'C')
		draw_block(game, game->img[C], window_y, window_x);
	else if (game->map->cont[y][x] == 'E')
		draw_block(game, game->img[E], window_y, window_x);
	else if (game->map->cont[y][x] == 'Z')
	{
		draw_block(game, game->img[E], window_y, window_x);
		draw_block(game, game->img[P], window_y, window_x);
	}
}

// update the window's bound
static void	update_camera(t_game *game)
{
	int	visible_width;
	int	visible_height;

	visible_width = game->map->window_width / game->map->block_len;
	visible_height = game->map->window_width / game->map->block_len;
	game->camera_pos.y = game->map->starting.y - visible_height / 2; 
	game->camera_pos.x = game->map->starting.x - visible_width / 2;
	ft_printf("camera_pos.x: %d, (int)game->map->window_width / BLOCK_SIZE / 2: %d\n", game->camera_pos.x, (int)game->map->window_width / BLOCK_SIZE / 2);
	// ft_printf("starting.y: %d, camera_pos.y: %d\n", game->camera_pos.y);

	//if small map
	if (game->map->window_width / BLOCK_SIZE < 25)
	{
		if (game->camera_pos.x < (int)game->map->cols)
			game->camera_pos.x = 0;
		if (game->camera_pos.y < (int)game->map->rows)
			game->camera_pos.y = 0;
	}
	else
	{
		if (game->camera_pos.x < (int)game->map->window_width / BLOCK_SIZE / 2) // vs 15/2
			game->camera_pos.x = 0;
		if (game->map->starting.y < (int)game->map->window_width / BLOCK_SIZE / 2)
			game->camera_pos.y = 0;
	}
	// if (game->camera_pos.x < (int)game->map->window_width / BLOCK_SIZE / 2) // vs 15/2
	// 	game->camera_pos.x = 0;
	// if (game->map->starting.y < (int)game->map->window_width / BLOCK_SIZE / 2)
	// 	game->camera_pos.y = 0;
	
	ft_printf("camera_pos.x: %d, map.cols: %d, visible_width: %d\n", game->camera_pos.x, game->map->cols, visible_width);
	ft_printf("camera_pos.y: %d, map.rows: %d, visible_height: %d\n", game->camera_pos.y, game->map->rows, visible_height);

	if (game->camera_pos.x > (int)game->map->cols - visible_width)
		game->camera_pos.x = (int)game->map->cols - visible_width;
	if (game->camera_pos.y > (int)game->map->rows - visible_height)
		game->camera_pos.y = (int)game->map->rows - visible_height;
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

	ft_printf("cam y: %d\n", y);

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
