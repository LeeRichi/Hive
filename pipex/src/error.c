/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:34 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 23:36:32 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	message_check_print(char *err)
{
	if (ft_strcmp(err, "dup2") == 0)
		ft_putstr_fd("dup2() error", STDERR);
	else if (ft_strcmp(err, "fork") == 0)
		ft_putstr_fd("fork() error", STDERR);
	else if (ft_strcmp(err, "pipe") == 0)
		ft_putstr_fd("pipe() creation failed", STDERR);
	else if (ft_strcmp(err, "malloc") == 0)
		ft_putstr_fd("malloc() failed", STDERR);
	else if (ft_strcmp(err, "permission") == 0)
		ft_putstr_fd("permission denied", STDERR);
	else if (ft_strcmp(err, "file_name") == 0)
		ft_putstr_fd("No such file or directory", STDERR);
	ft_putchar_fd('\n', STDERR);
}

static void	free_data(t_data *data)
{
	if (data->f1 >= 0)
		close(data->f1);
	if (data->f2 >= 0)
		close(data->f2);
	if (data->end[0] >= 0)
		close(data->end[0]);
	if (data->end[1 >= 0])
		close(data->end[1]);
}

void	show_error(t_data *data, char *message, int err_code)
{
	free_data(data);
	message_check_print(message);
	exit(err_code);
}
