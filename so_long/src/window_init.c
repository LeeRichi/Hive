/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/14 21:07:54 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"
#include <stdlib.h>
#include <stdio.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"

// void	handle_key(struct mlx_key_data keydata, void *param)
// {

// 	if (keydata.key == 256)
//     {
// 		delete_game(param);
// 		exit(0);
// 	}
// 	else if (keydata.key == 65)
// 	{
// 		ft_printf("go left, mother fucker\n");
// 	}
// 	else if (keydata.key == 83)
// 	{
// 		ft_printf("go down, mother fucker\n");
// 	}
// 	else if (keydata.key == 68)
// 	{
// 		ft_printf("go right, mother fucker\n");
// 	}
// 	else if (keydata.key == 87)
// 	{
// 		ft_printf("go up, mother fucker\n");
// 	}
// }

void	handle_key(struct mlx_key_data keydata, void *param)
{
	// Check if the key action is a press event
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == 256)
		{
			delete_game(param);
			exit(0);
		}
		else if (keydata.key == 65)
		{
			ft_printf("go left, motherfucker\n");
		}
		else if (keydata.key == 83)
		{
			ft_printf("go down, motherfucker\n");
		}
		else if (keydata.key == 68)
		{
			ft_printf("go right, motherfucker\n");
		}
		else if (keydata.key == 87)
		{
			ft_printf("go up, motherfucker\n");
		}
	}
}

void	close_window(void *param)
{
	t_game *game;

	game = param;
	delete_game(game);
	exit(0);
}

int window_init(t_game *game)
{
	game->disp.width = game->map->cols * BLOCK_SIZE;
	game->disp.height = game->map->rows * BLOCK_SIZE;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);

	game->disp.mlx = mlx_init(game->disp.width, game->disp.height, "so_long", true);

	if (!game->disp.mlx)
		show_error(game, "mlx_init error.");

    return (0);
}
