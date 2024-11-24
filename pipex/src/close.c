/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:24:14 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/24 18:49:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	double_close(int f1, int f2)
{
	if (f1 >= 0)
		close(f1);
	if (f2 >= 0)
		close(f2);
}

void	four_close(int f1, int f2, int end1, int end2)
{
	double_close(f1, f2);
	double_close(end1, end2);
}
