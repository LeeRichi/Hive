/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/27 14:06:09 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"
#include <stdlib.h>
#include <stdio.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"

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
			if (game->map->cont[y][x] == 'P')
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

static void	move_player(t_game *game, int new_y, int new_x)
{
	find_p(game);
	if (game->map->cont[new_y][new_x] == '1')
		return ;
	if (game->map->cont[new_y][new_x] == 'E' && game->map->coins > 0)
	{
		ft_printf("You are still too poor, can not get in.\n");
		return ;
	}
	game->map->movements++;
	ft_printf("You moved %d steps\n", game->map->movements);
	if (game->map->cont[new_y][new_x] == 'C')
		game->map->coins--;
	else if (game->map->cont[new_y][new_x] == 'E' && game->map->coins == 0)
	{
		delete_game(game);
		ft_printf("You win!\n");
		exit(EXIT_SUCCESS);
	}
	game->map->cont[game->map->starting.y][game->map->starting.x] = '0';
	game->map->starting.y = new_y;
	game->map->starting.x = new_x;
	game->map->cont[game->map->starting.y][game->map->starting.x] = 'P';
	draw_camera(game);
}

//export functions
void	handle_key(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	find_p(game);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == 256)
		{
			delete_game(param);
			exit(EXIT_SUCCESS);
		}
		else if (keydata.key == 65)
			move_player(game, game->map->starting.y, game->map->starting.x - 1);
		else if (keydata.key == 68)
			move_player(game, game->map->starting.y, game->map->starting.x + 1);
		else if (keydata.key == 83)
			move_player(game, game->map->starting.y + 1, game->map->starting.x);
		else if (keydata.key == 87)
			move_player(game, game->map->starting.y - 1, game->map->starting.x);
	}
}

void	close_window(void *param)
{
	t_game	*game;

	game = param;
	delete_game(game);
	exit(0);
}

//ww = window_width
int	window_init(t_game *game)
{
	unsigned int	ww;
	int				dw;

	game->disp.width = game->map->cols * BLOCK_SIZE;
	game->disp.height = game->map->rows * BLOCK_SIZE;
	dw = game->disp.width;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (game->disp.width < game->disp.height)
		game->map->window_width = game->disp.width;
	else
		game->map->window_width = game->disp.height;
	ww = game->map->window_width;
	if (game->map->cols > 25 || game->map->rows > 25)
		game->disp.mlx = mlx_init(ww, ww, "so_long", true);
	else
		game->disp.mlx = mlx_init(dw, game->disp.height, "so_long", true);
	if (!game->disp.mlx)
		show_error(game, "mlx_init error.");
	return (0);
}
