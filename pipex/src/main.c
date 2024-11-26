/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 16:33:55 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	pipex(t_data *data, char **av, char **envp)
{
	pid_t	pid[2];
	int		i;
	int		status;

	data->f1 = 0;
	data->f2 = 0;
	if (pipe(data->end) < 0)
		show_error(data, "Error: pipe() creation failed.", EXIT_FAILURE, NULL);
	i = -1;
	while ((++i) <= 1)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			show_error(data, "Error: fork() failed.", EXIT_FAILURE, NULL);
		if (pid[i] == 0)
			child_process(data, av, envp, i);
	}
	four_close(data->f1, data->f2, data->end[0], data->end[1]);
	i = -1;
	while ((++i) <= 1)
	{
		if (waitpid(pid[i], &status, 0) == -1)
			show_error(data, "Error: waitpid() failed.", EXIT_FAILURE, NULL);
	}
	return (status);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		status;
	int		exit_status;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		show_error(NULL, "Memory allocation failed", EXIT_FAILURE, NULL);
	status = pipex(data, av, envp);
	exit_status = (status >> 8) & 0xFF;
	free(data);
	return (exit_status);
}
