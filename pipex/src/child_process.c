/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:31:48 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 16:05:56 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*prepare_command(t_data *data, char *cmd, char **envp, char ***arg)
{
	char	*right_path;

	*arg = ft_split(cmd, ' ');
	if (!*arg)
		show_error(data, "Command split failed", EXIT_FAILURE, cmd);
	if (!ft_strchar((*arg)[0], '/'))
	{
		right_path = find_path(data, cmd, envp, *arg);
		if (!right_path)
		{
			ft_free_tab(*arg);
			show_error(data, "Executable path not found", EXIT_FAILURE, cmd);
		}
	}
	else
		right_path = (*arg)[0];
	return (right_path);
}

static int	execute_cmd(t_data *data, char *cmd, char **envp)
{
	char	*right_path;
	char	**arguments;
	int		signal;

	signal = 0;
	right_path = prepare_command(data, cmd, envp, &arguments);
	if (execve(right_path, arguments, envp) == -1)
	{
		if (errno == EACCES)
		{
			ft_free_tab(arguments);
			show_error(data, "Permission denied", 126, cmd);
		}
		ft_free_tab(arguments);
		show_error(data, "No such file or directory", 127, cmd);
		signal = -1;
	}
	free(right_path);
	ft_free_tab(arguments);
	double_close(data->f1, data->f2);
	return (signal);
}

static void	dup_pipe(int oldfd, int newfd, t_data *data, char *error_message)
{
	if (dup2(oldfd, newfd) == -1)
		show_error(data, error_message, EXIT_FAILURE, NULL);
}

static int	open_file(t_data *data, char *av, int i)
{
	int	fd;

	if (i == 0)
	{
		if (access(av, F_OK) == 0 && access(av, R_OK) == -1)
			show_error(data, "Permission denied", 1, av);
		fd = open(av, O_RDONLY, 0444);
	}
	else
	{
		if (access(av, F_OK) == 0 && access(av, W_OK) == -1)
			show_error(data, "Permission denied", 1, av);
		fd = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (fd == -1)
		show_error(data, "No such file or directory", 127, av);
	return (fd);
}

void	child_process(t_data *data, char **av, char **envp, int i)
{
	if (i == 0)
	{
		data->f1 = open_file(data, av[1], 0);
		dup_pipe(data->f1, 0, data, "dup2() failed for input redirection.");
		close(data->f1);
		dup_pipe(data->end[1], 1, data, "dup2() failed for pipe output.");
	}
	else
	{
		data->f2 = open_file(data, av[4], 1);
		dup_pipe(data->end[0], 0, data, "dup2() failed for pipe input.");
		dup_pipe(data->f2, 1, data, "dup2() failed for output redirection.");
		close(data->f2);
	}
	double_close(data->end[0], data->end[1]);
	if (is_empty_or_whitespace(av[i + 2]))
		show_error(data, "Command not found", 127, av[i + 2]);
	if (execute_cmd(data, av[i + 2], envp))
		show_error(data, "Command execution failed.", EXIT_FAILURE, av[i + 2]);
	double_close(data->f1, data->f2);
}
