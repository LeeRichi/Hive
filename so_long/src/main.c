// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/03 09:19:19 by chlee2            #+#    #+#             */
// /*   Updated: 2024/09/03 11:12:00 by chlee2           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../lib/minilibx_opengl/mlx.h"
#include "../includes/so_long.h"
#include "../lib/libft/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//temp
void	show_error(t_game *game, char *error_m)
{
	delete_game(game);
	ft_printf("Error: %s\n", error_m);
	exit(EXIT_FAILURE);
}

static void	arg_checker(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("so_long needs only one *.ber map as the second argument, plz try again.");
		exit(EXIT_FAILURE);
	}
	if(ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
	{
		ft_printf("Error: only accepts file that end with .ber");
		exit(EXIT_FAILURE);
	}
}

int count_row(t_game *game, char *ber_map)
{
	int i;
	int fd;
	char *res;

	fd = open(ber_map, O_RDONLY);
	if (fd < 0)
		show_error(game, "open file failed1.");
	i = 0;
	while (true)
	{
		res = get_next_line(fd);
		if (!res)
			break;
		i++;
		free(res);
	}
	close(fd);
	if(i > 132)
		show_error(game, "map to big, should be less than 132.");
	return (i);
}

t_map *calloc_map(int cols, int rows)
{
	t_map *map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->cont = ft_calloc(rows + 1, sizeof(char *));
	if (!map)
	{
		free(map);
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

void init_map(t_game *game, char *ber_map)
{
	unsigned int i;
	char *res;
	int fd;

	//first create an empty map
	game->map = calloc_map(0, count_row(game, ber_map));
	if(!game->map)
		show_error(game, "calloc failed.");

	//now assign the value to each row and col
	fd = open(ber_map, O_RDONLY);
	if (!fd)
		show_error(game, "open file faile2.");
	i = 0;
	while (i < game->map->rows)
	{
		res = get_next_line(fd);
		if (!res)
			show_error(game, "get_next_line failed.");
		game->map->cont[i] = ft_strtrim(res, "\n");
		if (!game->map->cont[i])
			show_error(game, "ft_strtrim failed?");
		else if (ft_strlen(game->map->cont[i]) > 132)
			show_error(game, "map to big, should be less than 132.");

		printf("Row %d: %s\n", i, game->map->cont[i]);  // Debugging statement

		i++;
		free(res);
	}
	close(fd);
}

void	game_init(char *ber_map)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));

	init_map(&game, ber_map);
	// map_checker();
}

int main(int ac, char **av)
{
	// t_game game;
	// t_mlx_data data;
	// void *params[2];

	arg_checker(ac, av);
	game_init(av[1]);

	return (0);
}
