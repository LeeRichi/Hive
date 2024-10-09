/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:52:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/08 23:49:37 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_error_close(t_game *game, int fd, char *str)
{
	close(fd);
	show_error(game, str);
}

static void	delete_image(t_game *game)
{
	int	i;

	if (!game->img)
		return ;
	i = 0;
	while (i < AMOUNT_OF_IMGS)
		mlx_delete_image(game->disp.mlx, game->img[i++]);
	free(game->img);
}

static void	delete_cont(t_map *map)
{
	unsigned int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->cont[i]);
		i++;
	}
	free(map->cont);
}

static void	delete_map(t_map *map)
{
	if (!map)
		return ;
	delete_cont(map);
	free(map);
}

void	delete_game(t_game *game)
{
	if (!game)
		return ;
	if (game->img)
		delete_image(game);
	if (game->map)
		delete_map(game->map);
	if (game->disp.mlx)
		mlx_terminate(game->disp.mlx);
}
