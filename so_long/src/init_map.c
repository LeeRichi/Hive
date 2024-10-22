/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:17:37 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/22 18:23:13 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_row(t_game *game, char *ber_map)
{
	int		i;
	int		fd;
	char	*res;

	fd = open(ber_map, O_RDONLY);
	if (fd < 0)
		show_error(game, "open file failed.");
	i = 0;
	while (true)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		i++;
		free(res);
	}
	close(fd);
	if (i > 132)
		show_error(game, "map to big, should be less than 132.");
	return (i);
}

static t_map	*calloc_map(int cols, int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->cont = ft_calloc(rows + 1, sizeof(char *));
	if (!map)
		return (NULL);
	map->cols = cols;
	map->rows = rows;
	return (map);
}

void	read_map_line(t_game *game, int fd, unsigned int i)
{
	char	*res;

	res = get_next_line(fd);
	if (!res)
		show_error_close(game, fd, "get_next_line failed.");
	game->map->cont[i] = ft_strtrim(res, "\n");
	if (!game->map->cont[i])
	{
		free(res);
		show_error_close(game, fd, "ft_strtrim failed.");
	}
	else if (ft_strlen(game->map->cont[i]) > 132)
		show_error_close(game, fd, "map too big, should be less than 132.");
	free(res);
}

void	load_map(t_game *game, int fd)
{
	unsigned int	i;

	i = 0;
	while (i < game->map->rows)
	{
		read_map_line(game, fd, i);
		i++;
	}
	if (!loop_cont(game))
		show_error(game, "Your map is in wrong shape.\n");
}

void	init_map(t_game *game, char *ber_map, int row_count)
{
	int	fd;

	game->map = calloc_map(0, row_count);
	if (!game->map)
		show_error(game, "calloc failed.");
	fd = open(ber_map, O_RDONLY);
	if (fd == -1)
		show_error(game, "open file failed.");
	load_map(game, fd);
	close(fd);
}
