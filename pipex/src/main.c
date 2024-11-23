/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/23 20:02:32 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//temp
#include <ctype.h>  // For isspace()

int is_empty_or_whitespace(char *str)
{
    if (str == NULL || str[0] == '\0') {
        return 1;  // String is empty
    }

    // Check if all characters are spaces or the string is empty
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            return 0;  // Found a non-space character
        }
    }

    return 1;  // String contains only spaces
}


static int execute_cmd(t_data *data, char *cmd, char **envp)
{
	char *right_path;
	char **arguments;
	int 	signal;

	right_path = NULL;
	signal = 0;
	arguments = ft_split(cmd, ' ');
	if (!arguments)
		show_error(data, "Command split failed", EXIT_FAILURE, cmd);

    if (is_empty_or_whitespace(cmd))
		show_error(data, "command not found", EXIT_FAILURE, cmd);

	if (arguments[0][0] != '/')
	{
		right_path = find_path(data, cmd, envp);
		if (!right_path)
		{
			ft_free_tab(arguments);
			show_error(data, "Executable path not found", EXIT_FAILURE, cmd);
		}
	} 
	else
		right_path = arguments[0];

	//print now the right_path
	// ft_putstr_fd("right_path: ", STDERR);
	// ft_putstr_fd(right_path, STDERR);
	// ft_putstr_fd("\n\n\n", STDERR);

	if (execve(right_path, arguments, envp) == -1)
	{
		show_error(data, "No such file or directory", 127, right_path);
		// ft_free_tab(arguments);
		// free(right_path);
		signal = -1;
	}
	ft_free_tab(arguments);
	free(right_path);
	return (signal);
}

static void dup_pipe(int oldfd, int newfd, t_data *data, char *error_message)
{
	if (dup2(oldfd, newfd) == -1)
		show_error(data, error_message, EXIT_FAILURE, NULL);
}

int open_file(t_data *data, char *av, int i)
{
	int fd;

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
	{
		// ft_putstr_fd(av, STDERR);
		// ft_putstr_fd(": ", STDERR);
		show_error(data, "No such file or directory", 127, av);
	}
	return (fd);
}

static void	child_process(t_data *data, char **av, char **envp, int i)
{
	if (i == 0)
	{
		data->f1 = open_file(data, av[1], 0);
		dup_pipe(data->f1, STDIN_FILENO, data, "Error: dup2() failed for input redirection.");
		dup_pipe(data->end[1], STDOUT_FILENO, data, "Error: dup2() failed for pipe output.");
	}
	else
	{
		data->f2 = open_file(data, av[4], 1);
		dup_pipe(data->end[0], STDIN_FILENO, data, "Error: dup2() failed for pipe input.");
		dup_pipe(data->f2, STDOUT_FILENO, data, "Error: dup2() failed for output redirection.");
	}
	double_close(data->end[0], data->end[1]);
	if (execute_cmd(data, av[i + 2], envp))
		show_error(data, "Error: Command execution failed.", EXIT_FAILURE, av[i + 2]);
}

static int	pipex(t_data *data, char **av, char **envp)
{
	pid_t	pid[2];
	int i;
	int status;

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
	int status;
	int exit_status;

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

