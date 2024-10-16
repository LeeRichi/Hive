/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:37:03 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 23:43:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/libft.h"

# define STDERR 2

typedef struct s_data
{
	int	f1;
	int	f2;
	int	end[2];

}	t_data;

//error.c
void	ft_free_tab(char **tab);
void	show_error(t_data *data, char *message, int err_code);

//close.c
void	double_close(int f1, int f2);
void	four_close(int f1, int f2, int end1, int end2);

//path_finder.c
char	*find_path(t_data *data, char *cmd, char **envp);

#endif
