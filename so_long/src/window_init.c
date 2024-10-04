/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/04 14:52:09 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_walkable(t_game *game, int new_y, int new_x)
{
	char	new;

	new = game->map->cont[new_y][new_x];
	return (new == '0' || new == 'C');
}

static int	f_norm(t_game *game, int new_y, int new_x)
{
	char	old;

	old = game->map->cont[game->map->starting.y][game->map->starting.x];
	return (is_walkable(game, new_y, new_x) && old == 'Z');
}

static void	move_player(t_game *game, int new_y, int new_x)
{
	int	temp_y;
	int	temp_x;
	// int	i;

	temp_y = game->camera_pos.y;
	temp_x = game->camera_pos.x;
	find_p(game);
	if (game->map->cont[new_y][new_x] == '1')
		return ;
	game->map->movements++;
	ft_printf("You moved %d steps\n", game->map->movements);

	// // Print the contents of the 2D array
	// ft_printf("Map content after move:\n");
	// for (i = 0; i < (int)game->map->rows; i++) // Assuming map height is stored in game->map->height
	// {
	// 	ft_printf("%s\n", game->map->cont[i]);
	// }
	if (game->map->cont[new_y][new_x] == 'C')
		game->map->coins--;
	else if (game->map->cont[new_y][new_x] == 'E' && game->map->coins == 0)
		you_win(game);
	if (game->map->cont[new_y][new_x] == 'E' && game->map->coins > 0)
		update_position(game, new_y, new_x, 'Z');
	if (f_norm(game, new_y, new_x))
		move_away(game, new_y, new_x);
	else if (is_walkable(game, new_y, new_x))
		update_position(game, new_y, new_x, 'P');
	update_camera(game);
	if (temp_y != game->camera_pos.y || temp_x != game->camera_pos.x)
		draw_camera(game);
	else
		update_player(game);
}

//export functions
void	handle_key(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	find_p(game);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			delete_game(param);
			exit(EXIT_SUCCESS);
		}
		else if (keydata.key == MLX_KEY_A)
			move_player(game, game->map->starting.y, game->map->starting.x - 1);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, game->map->starting.y, game->map->starting.x + 1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, game->map->starting.y + 1, game->map->starting.x);
		else if (keydata.key == MLX_KEY_W)
			move_player(game, game->map->starting.y - 1, game->map->starting.x);
	}
}

//ww = window_width
//if the map is big enough,
//we will open only a "square" window and display a part of map dynamically
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
