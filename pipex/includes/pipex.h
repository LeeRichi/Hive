/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:37:03 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 10:40:38 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"

#ifndef PIPEX_H
# define PIPEX_H

# define STDERR 2

typedef struct s_data
{
	int f1;
	int f2;
	int	end[2];

} t_data;

void
ft_free_tab(char **tab);
void	double_close(int f1, int f2);
void	four_close(int f1, int f2, int end1, int end2);
void	show_error(t_data *data, char *message, int err_code);

#endif
