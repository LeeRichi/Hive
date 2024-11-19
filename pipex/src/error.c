/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:34 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/18 16:24:41 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
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

// static void	message_check_print(char *err)
// {
// 	if (ft_strcmp(err, "dup2") == 0)
// 		write(STDERR_FILENO, "Error: dup2() failed\n", 22);
// 	else if (ft_strcmp(err, "fork") == 0)
// 		write(STDERR_FILENO, "Error: fork() failed\n", 22);
// 	else if (ft_strcmp(err, "pipe") == 0)
// 		write(STDERR_FILENO, "Error: pipe() creation failed\n", 30);
// 	else if (ft_strcmp(err, "malloc") == 0)
// 		write(STDERR_FILENO, "Error: malloc() failed\n", 24);
// 	else if (ft_strcmp(err, "permission") == 0)
// 		write(STDERR_FILENO, "Error: permission denied\n", 26);
// 	else if (ft_strcmp(err, "file_name") == 0)
// 		write(STDERR_FILENO, "Error: No such file or directory\n", 34);
// 		write(STDERR_FILENO, "Error: Unknown error occurred\n", 31);
// 	if (errno)
// 	{
// 		write(STDERR_FILENO, "System Error: ", 14);
// 		write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
// 		write(STDERR_FILENO, "\n", 1);
// 	}
// }

static void message_check_print(char *err)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, err, strlen(err));
	write(STDERR_FILENO, "\n", 1);
	// if (errno)
	// {
	// 	write(STDERR_FILENO, "System Error: ", 14);
	// 	write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
	// 	write(STDERR_FILENO, "\n", 1);
	// }
}


static void	free_data(t_data *data)
{
	if (!data)
		return;
	if (data->f1 >= 0)
		close(data->f1);
	if (data->f2 >= 0)
		close(data->f2);
	if (data->end[0] >= 0)
		close(data->end[0]);
	if (data->end[1] >= 0)
		close(data->end[1]);
	free(data);
}

void	show_error(t_data *data, char *message, int err_code)
{
	free_data(data);
	message_check_print(message);
	exit(err_code);
}
