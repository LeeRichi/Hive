/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/23 15:37:58 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#include <stdio.h>

void show_error(char *message)
{
	ft_printf("Error, %s\n", message);
}

char *find_path(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	**all_path;
	char	*one_path;

	char **s_cmd;
	char *exe;

	if (!envp)
		return (NULL);

	s_cmd = ft_split(cmd, ' ');
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_path = ft_split(envp[i] + 5, ':');
			if (!all_path)
				show_error("res split malloc failed.\n");
			j = -1;
            while (all_path[++j])
            {
                one_path = ft_strjoin(all_path[j], "/");
                exe = ft_strjoin(one_path, s_cmd[0]);

				if (access(exe, F_OK | X_OK) == 0)
                {
					printf("Found executable: %s\n", exe);  // Add this line

                    // ft_free_tab(all_path); // Free all_path to avoid memory leak
                    // ft_free_tab(s_cmd); // Free s_cmd as well
                    free(one_path); // Free one_path before returning
                    return (exe); // Return the found executable path
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

	printf("am i called?");

	arguments = ft_split(cmd, ' ');
	if (!arguments)
		show_error("Split failed on cmd.\n");

	right_path = find_path(cmd, envp);
	if (!right_path)
		show_error("can't find all_path.\n");

	printf("right_path.....: %s\n", right_path);
	if (execve(right_path, arguments, envp) == -1)
	{
		perror("execve failed!!!!");
		exit(EXIT_FAILURE);
	}
}

void child_process(int f1, char **av, int *end, char **envp)
{
	ft_printf("child\n");

    if (dup2(f1, STDIN_FILENO) < 0)
    {
		printf("dup21\n.");

        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }

	ft_printf("child2\n");

    if (dup2(end[1], STDOUT_FILENO) < 0)
    {
		printf("dup22\n.");

        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}

	ft_printf("child3\n");

	close(end[0]);
    close(f1);

	execute_cmd(av[2], envp);
}

void parent_process(int f2, char **av, int *end, char **envp)
{
	ft_printf("parents\n");

    if (dup2(end[0], STDIN_FILENO) < 0)
    {
        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}
    if (dup2(f2, STDOUT_FILENO) < 0)
    {
        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }
	close(end[1]);
	close(f2);

	execute_cmd(av[3], envp);
}


void pipex(int f1, int f2, char **av, char **envp)
{
    int   end[2];
    int   status;
	//temp
    // pid_t pid;
	pid_t child;
	pid_t parent;

	if (pipe(end) < 0)
    {
		perror("pipe failed");
		exit(EXIT_FAILURE);
    }

	//temp
	// if (pipe(end) == -1)
	// 	exit(-1);
	// pid = fork();
	// if (pid == -1)
	// 	exit(-1);
	// if (!pid)
	// 	child_process(f1, av, end, envp);
	// parent_process(f2, av, end, envp);

	//child
	child = fork();
	if (child < 0)
	{
	    perror("fork failed for child");
	    exit(EXIT_FAILURE);
	}
	if (child == 0)
        child_process(f1, av, end, envp);

    //parent
    parent = fork();
    if (parent < 0)
    {
        perror("fork failed for parent");
        exit(EXIT_FAILURE);
    }
    if (parent == 0)
        parent_process(f2, av, end, envp);

    // Close both ends of the pipe
    if (close(end[0]) < 0 || close(end[1]) < 0)
    {
        perror("close failed");
        exit(EXIT_FAILURE);
    }

    waitpid(child, &status, 0);  // Handle the return value if needed
    waitpid(parent, &status, 0);  // Handle the return value if needed
}

int main(int ac, char **av, char **envp)
{
	int f1;
	int f2;

	if (ac != 5)
	{
		ft_printf("Needs exact 4 arguments.\n");
		return (EXIT_FAILURE);
	}
    f1 = open(av[1], O_RDONLY);
    f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
    if (f1 < 0 || f2 < 0)
        return (-1);
    pipex(f1, f2, av, envp);
    return (0);
}
