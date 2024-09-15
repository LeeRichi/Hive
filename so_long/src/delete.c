/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:52:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/15 16:43:19 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"

static void delete_image(t_game *game)
{
	int i;

	if (!game->img)
		return;

	i = 0;
	//change 1 to something else later
	while (i < AMOUNT_OF_IMGS)
		mlx_delete_image(game->disp.mlx, game->img[i++]);
	free(game->img);
}

static void delete_cont(t_map *map)
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

static void delete_map(t_map *map)
{
	if (!map)
		return;
	delete_cont(map);
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
