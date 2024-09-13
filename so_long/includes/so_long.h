/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/13 23:53:39 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//temp
#include <stdint.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

typedef struct s_graph
{
	mlx_t	*mlx;
	int32_t	height;
	int32_t	width;

} t_graph;

typedef struct s_map
{
	//starting points
	t_point			starting;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	starts;
	unsigned int	exits;
	unsigned int	chests;
	unsigned int	players;
	char			**cont;
}	t_map;

typedef struct s_game
{
	char 		**grid;
	uint32_t 	row;
	uint32_t 	col;
	t_map 		*map;
	t_graph 	disp;
	mlx_image_t **img;
} t_game;

//main.c
void show_error(t_game *game, char *error_m);

//delete.c
void delete_game(t_game *game);

//map_checker.c
int map_checker(t_game *game);

//window.init.c
int	window_init(t_game *game);

#endif
