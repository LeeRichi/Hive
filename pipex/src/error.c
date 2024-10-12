/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:34 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 10:41:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
{
	int i;

	if (!tab)
		return;
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void double_close(int f1, int f2)
{
	close(f1);
	close(f2);
}

void four_close(int f1, int f2, int end1, int end2)
{
	double_close(f1, f2);
	double_close(end1, end2);
}

void message_checker(char *err)
{
	if (err == "dup2")
		ft_putstr_fd("dup2() error", STDERR);
	else if (err == "fork")
		ft_putstr_fd("fork() error", STDERR);
	else if (err == "pipe")
		ft_putstr_fd("pipe() creation failed", STDERR);
	else if (err == "malloc")
		ft_putstr_fd("malloc() failed", STDERR);
	else if (err == "permission")
		ft_putstr_fd("permission denied", STDERR);
	else if (err == "file_name")
		ft_putstr_fd("No such file or directory", STDERR);
	ft_putchar_fd('\n', STDERR);
}

void free_data(t_data *data)
{
	if (data->f1 >= 0)
		close(data->f1);
	if (data->f2 >= 0)
		close(data->f2);
	if (data->end[0])
		close(data->end[0]);
	if (data->end[1])
		close(data->end[1]);
}

void show_error(t_data *data, char *message, int err_code)
{
	free_data(data);
	message_check_print(message);
	exit(err_code);
}
