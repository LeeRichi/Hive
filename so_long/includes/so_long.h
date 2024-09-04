/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/03 16:01:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//temp
#include <stdint.h>
#include "../lib/libft/libft.h"

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx_data;

typedef struct s_pos
{
	uint32_t x;
	uint32_t y;
} t_pos;

// typedef struct s_game
// {

// 	char **grid;

// 	uint32_t row;
// 	uint32_t col;


// } t_game;

#endif
