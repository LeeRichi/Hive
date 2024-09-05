/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:52:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/05 22:22:32 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void delete_map(t_map *map)
// {

// }

void delete_game(t_game *game)
{
	if (!game)
		return;
	// if (game->img)
	// 	delete_image(game);
	// if (game->map)
	// 	delete_map(game->map);
	// if (game->disp.mlx)
	// 	mlx_terminate(game->disp.mlx);
}
