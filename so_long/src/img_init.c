/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:02:33 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/16 22:08:52 by chlee2           ###   ########.fr       */
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

// void draw_block(t_game *game, mlx_image_t *img, int y, int x)
// {
// 	if (mlx_image_to_window(game->disp.mlx, img, x * game->map->block_len, y * game->map->block_len) < 0)
// 		show_error(game, "mlx_image_to_window failed.");
// }

void draw_block(t_game *game, mlx_image_t *img, int y, int x, int cam_y, int cam_x)
{
    int window_y = (y - cam_y) * game->map->block_len;
    int window_x = (x - cam_x) * game->map->block_len;

    if (mlx_image_to_window(game->disp.mlx, img, window_x, window_y) < 0)
        show_error(game, "mlx_image_to_window failed.");
}


// void check_block(t_game *game, int y, int x)
// {
// 	draw_block(game, game->img[G], y, x);

// 	ft_printf("y: %d, x: %d\n", y, x);
// 	ft_printf("this: %c\n", game->map->cont[y][x]);

// 	if(game->map->cont[y][x] == '1')
// 		draw_block(game, game->img[W], y, x);
// 	else if (game->map->cont[y][x] == 'P')
// 		draw_block(game, game->img[P], y, x);
// 	else if (game->map->cont[y][x] == 'C')
// 		draw_block(game, game->img[C], y, x);
// 	else if (game->map->cont[y][x] == 'E')
// 		draw_block(game, game->img[E], y, x);
// }

void check_block(t_game *game, int y, int x, int cam_y, int cam_x)
{
    draw_block(game, game->img[G], y, x, cam_y, cam_x);

    // ft_printf("y: %d, x: %d\n", y, x);
    // ft_printf("this: %c\n", game->map->cont[y][x]);

    if (game->map->cont[y][x] == '1')
        draw_block(game, game->img[W], y, x, cam_y, cam_x);
    else if (game->map->cont[y][x] == 'P')
        draw_block(game, game->img[P], y, x, cam_y, cam_x);
    else if (game->map->cont[y][x] == 'C')
        draw_block(game, game->img[C], y, x, cam_y, cam_x);
    else if (game->map->cont[y][x] == 'E')
        draw_block(game, game->img[E], y, x, cam_y, cam_x);
}


// void draw_map(t_game *game)
// {
// 	unsigned int y;
// 	unsigned int x;

// 	y = 0;
// 	while (y < game->map->rows)
// 	{
// 		x = 0;
// 		while (x < game->map->cols)
// 		{
// 			check_block(game, y, x);
// 			x++;
// 		}
// 		y++;
// 	}
// }

//temp
void update_camera(t_game *game)
{
	// Ensure the camera stays within the bounds of the map
	//be aware of both are for width
	int visible_width = game->map->window_width / game->map->block_len;
	int visible_height = game->map->window_width / game->map->block_len;

	// ft_printf("visible_height: %d, width: %d\n", visible_height, visible_width);
	// ft_printf("starting p: %d, %d\n", game->map->starting.y, game->map->starting.x);

	game->camera_pos.y = game->map->starting.y - visible_height / 2;
	game->camera_pos.x = game->map->starting.x - visible_width / 2;

	// ft_printf("camera_pos.y: %d, x: %d\n", game->camera_pos.y, game->camera_pos.x);

	// Keep camera within map bounds
	if (game->camera_pos.x < 0) game->camera_pos.x = 0;
	if (game->camera_pos.y < 0) game->camera_pos.y = 0;
	if (game->camera_pos.x > (int)game->map->cols - visible_width)
		game->camera_pos.x = (int)game->map->cols - visible_width;
	if (game->camera_pos.y > (int)game->map->rows - visible_height)
		game->camera_pos.y = (int)game->map->rows - visible_height;

	// ft_printf("new camera pos y: %d, x: %d\n",game->camera_pos.y , game->camera_pos.x);
}


void draw_camera(t_game *game)
{
    int y;
    int x;

	int visible_width = game->disp.width / game->map->block_len;
	int visible_height = game->disp.width / game->map->block_len;

    update_camera(game);

	// Draw only the visible portion of the map (within the camera view)
    y = game->camera_pos.y;
    while (y < game->camera_pos.y + visible_height && y < (int)game->map->rows)
    {
        x = game->camera_pos.x;
        while (x < game->camera_pos.x + visible_width && x < (int)game->map->cols)
        {
			check_block(game, y, x, game->camera_pos.y, game->camera_pos.x);
			x++;
        }
        y++;
    }
}

// void draw_camera(t_game *game, int camera_width, int camera_height)
// {
// 	int start_x, start_y;
// 	unsigned int end_x, end_y;
// 	find_P(game);
// 	int player_x = (int)game->map->starting.x;	// Player's x position in grid
// 	int	player_y = (int)game->map->starting.y;  // Player's y position in grid

// 	ft_printf("%d, %d\n", player_x, player_y);

// 	// Calculate the starting point of the camera (center the camera on the player)
//     start_x = player_x - camera_width / 2;
//     start_y = player_y - camera_height / 2;

//     // Clamp the starting position to ensure the camera doesn't go out of bounds
//     if (start_x < 0) start_x = 0;
//     if (start_y < 0) start_y = 0;

//     // Calculate the end point of the camera
//     end_x = start_x + camera_width;
//     end_y = start_y + camera_height;

//     // Clamp the end position to ensure the camera doesn't go out of bounds
//     if (end_x > game->map->cols) end_x = game->map->cols;
//     if (end_y > game->map->rows) end_y = game->map->rows;

//     // Loop over the visible part of the map and render it
//     for (unsigned  y = start_y; y < end_y; y++)
//     {
//         for (unsigned x = start_x; x < end_x; x++)
//         {
//             check_block(game, y, x);  // Only draw blocks within the camera view
//         }
//     }
// }

