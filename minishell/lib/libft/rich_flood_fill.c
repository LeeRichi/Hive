/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rich_flood_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:51:18 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 14:24:34 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//t = tab, sz = size, b = begin
void	rich_flood_fill(char **t, t_point sz, t_point b)
{
	t[b.y][b.x] = 'F';
	if (b.x > 0 && t[b.y][b.x - 1] != '1' && t[b.y][b.x - 1] != 'F')
	{
		b.x = b.x - 1;
		rich_flood_fill(t, sz, b);
	}
	if (b.x < (sz.x - 1) && t[b.y][b.x + 1] != '1' && t[b.y][b.x + 1] != 'F')
	{
		b.x = b.x + 1;
		rich_flood_fill(t, sz, b);
	}
	if (b.y > 0 && t[b.y - 1][b.x] != '1' && t[b.y - 1][b.x] != 'F')
	{
		b.y = b.y - 1;
		rich_flood_fill(t, sz, b);
	}
	if (b.y < (sz.y - 1) && t[b.y + 1][b.x] != '1' && t[b.y + 1][b.x] != 'F')
	{
		b.y = b.y + 1;
		rich_flood_fill(t, sz, b);
	}
}
