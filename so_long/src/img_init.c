/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:02:33 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/15 15:43:58 by chlee2           ###   ########.fr       */
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
		show_error(game, "png to texture failed");

	mlx_image_t *img = mlx_texture_to_image(game->disp.mlx, texture);
	if (!img)
		show_error(game, "texture to image has failed.");
	if (!mlx_resize_image(img, game->map->block_len, game->map->block_len))
		show_error(game, "mlx_resize_image has failed.");
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

	ft_printf("tell me the value of block_len: %d\n", game->map->block_len);
	game->img[G] = rich_from_png_to_texture(game, "./assets/ground/ground.png");
	game->img[W] = rich_from_png_to_texture(game, "./assets/barrier/Bushe.png");
	game->img[P] = rich_from_png_to_texture(game, "./assets/player/single.png");
	game->img[C] = rich_from_png_to_texture(game, "./assets/spinning_coin/coin10.png");
	game->img[E] = rich_from_png_to_texture(game, "./assets/house/House.png");
}

void draw_block(t_game *game, mlx_image_t *img, int y, int x)
{
	if (mlx_image_to_window(game->disp.mlx, img, x * game->map->block_len, y * game->map->block_len) < 0)
		show_error(game, "mlx_image_to_window failed.");
}

void check_block(t_game *game, int y, int x)
{
	if(game->map->cont[y][x] == '1')
		draw_block(game, game->img[W], y, x);
	else if (game->map->cont[y][x] == '0')
		draw_block(game, game->img[G], y, x);
	else if (game->map->cont[y][x] == 'P')
		draw_block(game, game->img[P], y, x);
	else if (game->map->cont[y][x] == 'C')
		draw_block(game, game->img[C], y, x);
	else if (game->map->cont[y][x] == 'E')
	{
		draw_block(game, game->img[E], y, x);
		ft_printf("test");
	}
}

void draw_map(t_game *game)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	while (y < game->map->rows) //01234
	{
		x = 0;
		while (x < game->map->cols) //0123456
		{
			check_block(game, y, x);
			x++;
			printf("%d", game->map->cont[y][x]);
		}
		printf("\n");
		y++;
	}
}
