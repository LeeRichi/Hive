/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:19:19 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/02 19:15:27 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_error(t_game *game, char *error_m)
{
	delete_game(game);
	ft_printf("Error: %s\n", error_m);
	exit(EXIT_FAILURE);
}

void	errow_and_temp(t_game *game, char *error_m, char **temp)
{
	free_copy(temp, game->map->rows);
	delete_game(game);
	ft_printf("Error: %s\n", error_m);
	exit(EXIT_FAILURE);
}

static void	arg_checker(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("so_long takes only one *.ber map as the second argument.");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
	{
		ft_printf("Error: only accepts file that end with .ber");
		exit(EXIT_FAILURE);
	}
}

static void	game_init(char *ber_map)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	init_map(&game, ber_map);
	map_checker(&game);
	window_init(&game);
	rich_from_texture_to_img(&game);
	draw_ground(&game);
	draw_camera(&game);
	mlx_key_hook(game.disp.mlx, (mlx_keyfunc)handle_key, &game);
	mlx_close_hook(game.disp.mlx, close_window, &game);
	mlx_loop(game.disp.mlx);
}

int	main(int ac, char **av)
{
	arg_checker(ac, av);
	game_init(av[1]);
	return (0);
}
