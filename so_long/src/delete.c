/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:52:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/12 16:00:06 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"

static void delete_image(t_game *game)
{
	int i;

	i = 0;
	while (i < AMOUNT_OF_IMGS)
	{
		mlx_delete_image(game->disp.mlx, game->img[i++]);
		free(game->img);
	}
}

static void delete_cont(char **cont)
{
	int	i;

	if (!cont)
		return ;
	i = 0;
	while (i < AMOUNT_OF_IMGS)
	{
		free(cont[i]);
		i++;
	}

	free(cont);
}

static void delete_map(t_map *map)
{
	if (!map)
		return;

	delete_cont(map->cont);
	free(map);
}

void delete_game(t_game *game)
{
	if (!game)
		return;
	if (game->img)
		delete_image(game);
	if (game->map)
		delete_map(game->map);
	if (game->disp.mlx)
		mlx_terminate(game->disp.mlx);
}
