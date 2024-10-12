/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/10/12 10:42:24 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *find_path(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	**all_path;
	char	*one_path;

	char	**s_cmd;
	char	*exe;

	if (!envp)
		return (NULL);
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		show_error("s_cmd split malloc failed.\n");
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_path = ft_split(envp[i] + 5, ':');
			if (!all_path)
				show_error("all_path split malloc failed.\n", EXIT_FAILURE);
			j = -1;
            while (all_path[++j])
            {
                one_path = ft_strjoin(all_path[j], "/");
				if (!one_path)
					return (NULL);
				exe = ft_strjoin(one_path, s_cmd[0]);
				if (!exe)
					return (NULL);
				if (access(exe, F_OK | X_OK) == 0)
				{
                    ft_free_tab(all_path);
                    ft_free_tab(s_cmd);
                    free(one_path);
                    return (exe);
                }
                free(exe); // Free exe if not found
                free(one_path); // Free one_path if not found
            }
		}
	}
	return (NULL);
}

void execute_cmd(char *cmd, char **envp)
{
	char *right_path;
	char **arguments;

	arguments = ft_split(cmd, ' ');
	if (!arguments)
		show_error("Split failed on cmd.\n");
	right_path = find_path(cmd, envp);
	if (!right_path)
	{
		ft_printf("command not found: %s\n", cmd);
		show_error("can't find all_path.\n", EXIT_FAILURE);
	}
	if (execve(right_path, arguments, envp) == -1)
	{
		ft_printf("execve failed...\n");
		perror("execve failed!!!!");
		exit(EXIT_FAILURE);
	}
}

void child_process(int f1, char **av, int *end, char **envp)
{
    if (dup2(f1, STDIN_FILENO) < 0)
    {
		printf("dup2 if\n.");

        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }
	if (dup2(end[1], STDOUT_FILENO) < 0)
    {
		printf("dup2-2 if \n.");

        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}
	close(end[0]);
	execute_cmd(av[2], envp);
}

void parent_process(int f2, char **av, int *end, char **envp)
{
    if (dup2(f2, STDOUT_FILENO) < 0)
    {
        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }
    if (dup2(end[0], STDIN_FILENO) < 0)
    {
        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}
	close(end[1]);
	execute_cmd(av[3], envp);
}


void pipex(t_data *data, char **av, char **envp)
{
    // int		end[2];
	pid_t	child1;
	pid_t	child2;

	if (pipe(data->end) < 0)
		show_error(data, "pipe", EXIT_FAILURE);
    child1 = fork();
    if (child1 < 0)
    {
		// four_close(data->f1, data->f2, data->end[0], data->end[1]);
		show_error(data, "fork", EXIT_FAILURE);
    }
    if (child1 == 0)
    {
        if (dup2(f1, STDIN_FILENO) == -1)
			show_error("dup2", EXIT_FAILURE);
        if (dup2(end[1], STDOUT_FILENO) == -1)
			show_error("dup2", EXIT_FAILURE);
		double_close(end[0], end[1]);
        execute_cmd(av[2], envp);
    }
    child2 = fork();
    if (child2 < 0)
    {
		four_close(f1, f2, end[0], end[1]);
		show_error("fork", EXIT_FAILURE);
    }
    if (child2 == 0)
    {
        if (dup2(end[0], STDIN_FILENO) == -1)
			show_error("dup2", EXIT_FAILURE);
        if (dup2(f2, STDOUT_FILENO) == -1)
			show_error("dup2", EXIT_FAILURE);
		double_close(end[0], end[1]);
        execute_cmd(av[3], envp);
    }
    // Parent process code
	four_close(f1, f2, end[0], end[1]);
	// Wait for both child processes to finish
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
}

int main(int ac, char **av, char **envp)
{
	t_data *data;
	// int f1;
	// int f2;

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
