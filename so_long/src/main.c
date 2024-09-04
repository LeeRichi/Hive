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
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


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

	uint32_t row;
	uint32_t col;

} t_game;


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
		// to_do, show error
		// ft_error();
		printf("Failed to open file.");
	while (true)
	{
		res = get_next_line(fd);
		if (!res)
			break;
		i++;
		free(res);
	}
	close(fd);
	if(i > "big value")
		show_error();
	return (i);
}

t_map create_map(int x, int y)
{
	t_map *map;


}

void init_map(t_game *game, char *ber_map)
{
	int i;
	char *res;
	int fd;

	game->map = (0, count_row(game, ber_map));
	if(!game->map)
		show_error();
	
}

void	game_init(char *ber_map)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));

	init_map(&game, ber_map);
	map_checker();
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
