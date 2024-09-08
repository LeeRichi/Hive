/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:21:19 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/08 18:21:22 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;
	t_point new_begin;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';

	if(begin.x > 0 && tab[begin.y][begin.x - 1] == c)
	{
		new_begin.x = begin.x - 1;
		new_begin.y = begin.y;
		flood_fill(tab, size, new_begin);
	}
	if(begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] == c)
	{
		new_begin.x = begin.x + 1;
		new_begin.y = begin.y;
		flood_fill(tab, size, new_begin);
	}
	if(begin.y > 0 && tab[begin.y - 1][begin.x] == c)
	{
		new_begin.x = begin.x;
		new_begin.y = begin.y - 1;
		flood_fill(tab, size, new_begin);
	}
	if(begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] == c)
	{
		new_begin.x = begin.x;
		new_begin.y = begin.y + 1;
		flood_fill(tab, size, new_begin);
	}
}


// #include <stdlib.h>
// #include <stdio.h>

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
