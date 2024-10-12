/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 23:34:27 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	execute_cmd(t_data *data, char *cmd, char **envp)
{
	char	*right_path;
	char	**arguments;

	arguments = ft_split(cmd, ' ');
	if (!arguments)
		show_error(data, "split failed on cmd", EXIT_FAILURE);
	right_path = find_path(data, cmd, envp);
	if (!right_path)
		show_error(data, "can't find all_path.", EXIT_FAILURE);
	if (execve(right_path, arguments, envp) == -1)
		show_error(data, "exe failed", EXIT_FAILURE);
}

static void	child_process(t_data *data, char **av, char **envp)
{
	if (dup2(data->f1, STDIN_FILENO) == -1)
		show_error(data, "dup2", EXIT_FAILURE);
	if (dup2(data->end[1], STDOUT_FILENO) == -1)
		show_error(data, "dup2", EXIT_FAILURE);
	double_close(data->end[0], data->end[1]);
	execute_cmd(data, av[2], envp);
}

static void	parent_process(t_data *data, char **av, char **envp)
{
	if (dup2(data->end[0], STDIN_FILENO) == -1)
		show_error(data, "dup2", EXIT_FAILURE);
	if (dup2(data->f2, STDOUT_FILENO) == -1)
		show_error(data, "dup2", EXIT_FAILURE);
	double_close(data->end[0], data->end[1]);
	execute_cmd(data, av[3], envp);
}

static void	pipex(t_data *data, char **av, char **envp)
{
	pid_t	child1;
	pid_t	child2;

	if (pipe(data->end) < 0)
		show_error(data, "pipe", EXIT_FAILURE);
	child1 = fork();
	if (child1 < 0)
		show_error(data, "fork", EXIT_FAILURE);
	if (child1 == 0)
		child_process(data, av, envp);
	child2 = fork();
	if (child2 < 0)
		show_error(data, "fork", EXIT_FAILURE);
	if (child2 == 0)
		parent_process(data, av, envp);
	four_close(data->f1, data->f2, data->end[0], data->end[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Memory allocation failed for data.\n");
		return (EXIT_FAILURE);
	}
	if (ac != 5)
	{
		ft_printf("Needs exact 4 arguments.\n");
		return (EXIT_FAILURE);
	}
	data->f1 = open(av[1], O_RDONLY);
	data->f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->f1 < 0 || data->f2 < 0)
		return (-1);
	pipex(data, av, envp);
	return (0);
}
