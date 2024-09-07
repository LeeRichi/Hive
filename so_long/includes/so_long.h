/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/07 17:46:02 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//temp
#include <stdint.h>
# include "../lib/minilibx_opengl/mlx.h"
#include "../lib/libft/libft.h"

// typedef struct s_img
// {

// }	t_img;

typedef struct s_graph
{
	// mlx_t	*mlx;
	int height;
	int width;

} t_graph;

typedef struct s_map
{
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

	char **grid;

	t_map *map;
	// t_img *img;

	uint32_t row;
	uint32_t col;

	t_graph disp;

} t_game;

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


//main.c


//delete.c
void delete_game(t_game *game);

//map_checker.c
int map_checker(t_game *game);

// typedef struct s_game
// {

// 	char **grid;

// 	uint32_t row;
// 	uint32_t col;


// } t_game;

#endif
