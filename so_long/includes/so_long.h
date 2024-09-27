/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/27 14:15:10 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "constants.h"
# include "../lib/libft/libft.h"

//to communicate with mlx server
typedef struct s_graph
{
	mlx_t	*mlx;
	int32_t	height;
	int32_t	width;

}	t_graph;

//map's detail
typedef struct s_map
{
	t_point			starting;
	t_point			flood_begin;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	coins;
	unsigned int	movements;
	unsigned int	block_len;
	unsigned int	window_width;
	unsigned int	window_height;
	char			**cont;
}	t_map;

typedef struct s_game
{
	t_point		camera_pos;
	t_map		*map;
	t_graph		disp;
	mlx_image_t	**img;
}	t_game;

//main.c
void	show_error(t_game *game, char *error_m);

//delete.c
void	delete_game(t_game *game);

//map_checker.c
void	map_checker(t_game *game);

//window.init.c
//find_p is called for also map_checker.c for flood.
void	find_p(t_game *game);
void	handle_key(struct mlx_key_data keydata, void *param);
void	close_window(void *param);
int		window_init(t_game *game);

//img_init.c
void	rich_from_texture_to_img(t_game *game);

//deep_copy.c
char	**deep_copy(char **source, unsigned int rows, unsigned int cols);
void	free_copy(char **temp, int rows);

//init_map.c
void	init_map(t_game *game, char *ber_map);

//draw_camera.c
void	draw_camera(t_game *game);

#endif
