/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:21:19 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 10:49:12 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x > 0 && tab[begin.y][begin.x - 1] == c)
	{
		begin.x = begin.x - 1;
		flood_fill(tab, size, begin);
	}
	if (begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] == c)
	{
		begin.x = begin.x + 1;
		flood_fill(tab, size, begin);
	}
	if (begin.y > 0 && tab[begin.y - 1][begin.x] == c)
	{
		begin.y = begin.y - 1;
		flood_fill(tab, size, begin);
	}
	if (begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] == c)
	{
		begin.y = begin.y + 1;
		flood_fill(tab, size, begin);
	}
}
