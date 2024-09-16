/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/16 22:07:45 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"
#include <stdlib.h>
#include <stdio.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"

void find_P(t_game *game)
{
	unsigned int x;
	unsigned int y;

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

void move_player(t_game *game, int new_y, int new_x)
{
	find_P(game);
	if (game->map->cont[new_y][new_x] == '1')
		return ;
	if (game->map->cont[new_y][new_x] == 'E' && game->map->collectibles > 0)
	{
		ft_printf("You are still too poor, can not get in.\n");
		return;
	}
	game->map->movements++;
	ft_printf("You moved %d steps\n", game->map->movements);

	if (game->map->cont[new_y][new_x] == 'C')
		game->map->collectibles--;
	else if (game->map->cont[new_y][new_x] == 'E' && game->map->collectibles == 0)
	{
		delete_game(game);
		ft_printf("You win!\n");
		exit(EXIT_SUCCESS);
	}
	game->map->cont[game->map->starting.y][game->map->starting.x] = '0';
	game->map->starting.y = new_y;
	game->map->starting.x = new_x;
	game->map->cont[game->map->starting.y][game->map->starting.x] = 'P';
	// draw_map(game);
	draw_camera(game);
}

//export functions
void	handle_key(struct mlx_key_data keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	find_P(game);
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
	t_game *game;

	game = param;
	delete_game(game);
	exit(0);
}

int	window_init(t_game *game)
{
	ft_printf("1.%d, %d\n", game->map->cols, game->map->rows);

	// game->disp.width = game->map->cols * BLOCK_SIZE;
	// game->disp.height = game->map->rows * BLOCK_SIZE;

	ft_printf("2.%d, %d\n", game->disp.width, game->disp.height);

	game->disp.width = game->map->cols * BLOCK_SIZE;
	game->disp.height = game->map->rows * BLOCK_SIZE;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);

	ft_printf("3.%d, %d\n", game->disp.width,game->disp.height);

	if(game->disp.width < game->disp.height)
		game->map->window_width = game->disp.width;
	else
		game->map->window_width = game->disp.height;

	// game->map->window_width = game->disp.width;
	// game->map->window_height = game->disp.height;

	//ref
	//mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)
	game->disp.mlx = mlx_init(game->map->window_width, game->map->window_width, "so_long", true);
	if (!game->disp.mlx)
		show_error(game, "mlx_init error.");
    return (0);
}
