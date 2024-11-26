/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:37:03 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 13:30:08 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/libft.h"

# define STDERR 2
# define FAILFCMD 127

#include <sys/wait.h>

typedef struct s_data
{
	int	f1;
	int	f2;
	int	end[2];

}	t_data;

int is_empty_or_whitespace(char *str);

//error.c
void	ft_free_tab(char **tab);
// void	show_error(t_data *data, char *message, int err_code);
void show_error(t_data *data, char *message, int err_code, char *av);
void show_error_for_sc(t_data *data, char *message, int err_code, char *av);

//close.c
void	double_close(int f1, int f2);
void	four_close(int f1, int f2, int end1, int end2);

//path_finder.c
char	*find_path(t_data *data, char *cmd, char **envp, char **arguments);

#endif
