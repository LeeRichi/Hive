/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/16 13:33:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdint.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

//to communicate with mlx server
typedef struct s_graph
{
	mlx_t	*mlx;
	int32_t	height;
	int32_t	width;

} t_graph;

//map's detail
typedef struct s_map
{
	t_point			starting;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	players;
	unsigned int	collectibles;
	unsigned int	exits;
	unsigned int	movements;
	unsigned int 	block_len;
	char 			**cont;
}	t_map;

typedef struct s_game
{
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
//find_P is called for also map_checker.c for flood.
void find_P(t_game *game);
void handle_key(struct mlx_key_data keydata, void *param);
void close_window(void *param);
int	window_init(t_game *game);

void draw_map(t_game *game);

//temp
void draw_camera(t_game *game, int camera_width, int camera_height);

//img_init.c
void rich_from_texture_to_img(t_game *game);

#endif
