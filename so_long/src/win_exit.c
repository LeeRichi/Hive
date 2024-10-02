/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:27:20 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/02 15:32:15 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	you_win(t_game *game)
{
	delete_game(game);
	ft_printf("You win!\n");
	exit(EXIT_SUCCESS);
}
