/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:52:17 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/04 16:54:50 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_movements(t_game *game, int new_y, int new_x)
{
	if (game->map->cont[new_y][new_x] == 'C')
		game->map->coins--;
	if (game->map->cont[new_y][new_x] == 'E' && game->map->coins == 0)
		you_win(game);
	if (game->map->cont[new_y][new_x] == 'E' && game->map->coins > 0)
		update_position(game, new_y, new_x, 'Z');
	if (f_norm(game, new_y, new_x))
		move_away(game, new_y, new_x);
	if (is_walkable(game, new_y, new_x))
		update_position(game, new_y, new_x, 'P');
}
