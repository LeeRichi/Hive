/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:02:33 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/14 15:56:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/constants.h"

//refer
// mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);
// bool mlx_resize_image(mlx_image_t *img, uint32_t nwidth, uint32_t nheight);

//local functions
static void count_block_len(t_game *game)
{
	unsigned width;
	unsigned height;

	width = game->disp.width / game->map->cols;
	height = game->disp.height / game->map->rows;

	if (width > height)
		game->map->block_len = height;
	else
		game->map->block_len = width;
}

static mlx_image_t *rich_from_png_to_texture(t_game *game, const char *file_path)
{
    mlx_texture_t *texture = mlx_load_png(file_path);
    if (!texture)
		show_error(game, "game img malloc failed");

	mlx_image_t *img = mlx_texture_to_image(game->disp.mlx, texture);
	if (!img)
		show_error(game, "texture to imgae has failed.");
	if (!mlx_resize_image(img, game->map->block_len, game->map->block_len))
		show_error(game, "mlx_resize_imgae has failed.");
	return (img);
}

//output function
//assgin value of "game->map.block_len" and "game->*img"
void rich_from_texture_to_img(t_game *game)
{
	game->img = malloc(sizeof(mlx_image_t) * AMOUNT_OF_IMGS);
	if (!game->img)
		show_error(game, "game img malloc failed");
	count_block_len(game);

	ft_printf("tell me the value of: %d\n", game->map->block_len);
	// game->img[W] = load_texture(game->disp.mlx, "../assets/P.png");
	game->img[P] = rich_from_png_to_texture(game, "./assets/right.png");
	// game->img[C] = load_texture(game->disp.mlx, "../assets/P.png");
	// game->img[E] = rich_from_png_to_texture(game, "./assets/E.png");
}
