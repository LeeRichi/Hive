/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:02:33 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/30 21:56:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//local functions
static void	count_block_len(t_game *game)
{
	unsigned int	width;
	unsigned int	height;

	width = game->disp.width / game->map->cols;
	height = game->disp.height / game->map->rows;
	if (width > height)
		game->map->block_len = height;
	else
		game->map->block_len = width;
}

//fp = file_path
static mlx_image_t	*rich_from_png_to_texture(t_game *game, const char *fp)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(fp);
	if (!texture)
		show_error(game, "png to texture failed");
	img = mlx_texture_to_image(game->disp.mlx, texture);
	if (!img)
		show_error(game, "texture to image has failed.");
	if (!mlx_resize_image(img, game->map->block_len, game->map->block_len))
		show_error(game, "mlx_resize_image has failed.");
	return (img);
}

//output function
//assgin value of "game->map.block_len" and "game->*img"
void	rich_from_texture_to_img(t_game *game)
{
	game->img = malloc(sizeof(mlx_image_t) * AMOUNT_OF_IMGS);
	if (!game->img)
		show_error(game, "game img malloc failed");
	count_block_len(game);
	game->img[G] = rich_from_png_to_texture(game, "./assets/ground/ground.png");
	game->img[W] = rich_from_png_to_texture(game, "./assets/barrier/Bushe.png");
	game->img[P] = rich_from_png_to_texture(game, "./assets/player/single.png");
	game->img[C] = rich_from_png_to_texture(game, "./assets/coins/coin10.png");
	game->img[E] = rich_from_png_to_texture(game, "./assets/house/House.png");
}
