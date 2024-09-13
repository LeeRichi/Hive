/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/13 13:42:15 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"
#include <stdlib.h>
#include <stdio.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"

mlx_keyfunc	handle_key(int key, void *param)
{
	// void **params = (void **)param;
    // void *mlx_ptr = params[0];
    // void *win_ptr = params[1];
	printf("%d-key pressed.\n", key);
    if (key == 53)
    {
		delete_game(param);
		exit(0);
	}
    return (0);
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

	// Handle key press events
    mlx_key_hook(game->disp.mlx, (mlx_keyfunc)handle_key, &game);
    // Handle the window close event
    mlx_close_hook(game->disp.mlx, close_window, &game);
    // Start the event loop
    mlx_loop(game->disp.mlx);

	//older code that run with opengl
    // Clean up resources (though it will not be reached)
    // mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    // free(data.mlx_ptr);
    return (0);
}

