/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/15 15:24:21 by chlee2           ###   ########.fr       */
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
	unsigned int 	block_len;
	char **cont;
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
void handle_key(struct mlx_key_data keydata, void *param);
void close_window(void *param);
int	window_init(t_game *game);

void draw_map(t_game *game);

//img_init.c
void rich_from_texture_to_img(t_game *game);

#endif
