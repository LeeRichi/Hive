/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/03 14:41:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_opengl/mlx.h"
#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

int handle_key(int key, void *param)
{
	void **params = (void **)param;
    void *mlx_ptr = params[0];
    void *win_ptr = params[1];

	printf("%d\n", key);
    if (key == 53)
    {
    	mlx_destroy_window(mlx_ptr, win_ptr);
        exit(0);
    }
    return (0);
}

int close_window(void *param)
{
	void **params = (void **)param;
    void *mlx_ptr = params[0];
    void *win_ptr = params[1];

    mlx_destroy_window(mlx_ptr, win_ptr);
    exit(0);
    return (0);
}

int window_init(void)
{
	t_mlx_data data;
	void *params[2];

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
    if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	params[0] = data.mlx_ptr;
    params[1] = data.win_ptr;

    // Handle key press events
    mlx_key_hook(data.win_ptr, handle_key, params);

    // Handle the window close event
    mlx_hook(data.win_ptr, 17, 0, close_window, params);

    // Start the event loop
    mlx_loop(data.mlx_ptr);

    // Clean up resources (though it will not be reached)
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    free(data.mlx_ptr);
    return (0);
}

