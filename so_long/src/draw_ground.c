/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:00:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/02 17:44:20 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//bl = block_len;
void	draw_ground(t_game *game)
{
	int	x;
	int	y;
	int	bl;

	bl = game->map->block_len;
	y = 0;
	while (y < (int)game->map->rows)
	{
		x = 0;
		while (x < (int)game->map->cols)
		{
			draw_block(game, game->img[G], y * bl, x * bl);
			x++;
		}
		y++;
	}
}
