/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:00:59 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/09 00:09:00 by chlee2           ###   ########.fr       */
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
	t_point			old;
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
void	errow_and_temp(t_game *game, char *error_m, char **temp);

//delete.c
void	show_error_close(t_game *game, int fd, char *str);
void	delete_game(t_game *game);

//flood_packs
int		flood_check(t_game *game, char **temp);

//map_checker.c
void	map_checker(t_game *game);

//window_init.c
//find_p is called for also map_checker.c for flood.
void	handle_key(struct mlx_key_data keydata, void *param);
int		window_init(t_game *game);
int		f_norm(t_game *game, int new_y, int new_x);
int		is_walkable(t_game *game, int new_y, int new_x);

//window_init_helpers.c
void	find_p(t_game *game);
void	close_window(void *param);
void	inject_old(t_game *game);
void	update_position(t_game *game, int new_y, int new_x, char new_tile);
void	move_away(t_game *game, int new_y, int new_x);

//img_init.c
void	rich_from_texture_to_img(t_game *game);

//deep_copy.c
char	**deep_copy(char **source, unsigned int rows, unsigned int cols);
void	free_copy(char **temp, int rows);

//init_map.c
int		count_row(t_game *game, char *ber_map);
void	init_map(t_game *game, char *ber_map, int row_count);

//draw_ground.c
void	draw_ground(t_game *game);

//draw_camera.c
void	draw_block(t_game *game, mlx_image_t *img, int wy, int wx);
void	update_camera(t_game *game);
void	draw_camera(t_game *game);
void	update_player(t_game *game);

//win_exit.c
void	you_win(t_game *game);

//valid_movements.c
void	valid_movements(t_game *game, int new_y, int new_x);

//check_block.c
void	check_block(t_game *game, int y, int x, int is_big_map);

#endif
