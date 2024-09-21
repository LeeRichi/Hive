/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/21 20:22:20 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void execute_cmd(char **av, char **envp)
{
    find_path();
}

void child_process(int f1, char **av, int *end, char **envp)
{
    // Redirect input from the file (f1)
    if (dup2(f1, STDIN_FILENO) < 0)
    {
        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }

    // Redirect output to the pipe (end[1])
    if (dup2(end[1], STDOUT_FILENO) < 0)
    {
        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}

	close(end[0]); // Close the read end of the pipe (no need in child_one)
    close(f1);     // Close the input file descriptor
                  
    // Execute the command (replace with execve or similar)
    // if (execve("PATH", av[2], envp) == -1) // NULL is placeholder, replace accordingly
    // {
    //     perror("execve failed");
    //     exit(EXIT_FAILURE); // Exit child process if execve fails
    // }
    if (execve("PATH", av[2], envp) == -1) // NULL is placeholder, replace accordingly
    {
        perror("execve failed");
        exit(EXIT_FAILURE); // Exit child process if execve fails
    }
}

void parent_process(int f2, char **av, int *end, char **envp)
{
    char **paths;
    char *path;
    // Redirect input from the file (f1)
    if (dup2(f2, STDIN_FILENO) < 0)
    {
        perror("dup2 failed for f1");
        exit(EXIT_FAILURE);
    }

    // Redirect output to the pipe (end[1])
    if (dup2(end[1], STDOUT_FILENO) < 0)
    {
        perror("dup2 failed for end[1]");
		exit(EXIT_FAILURE);
	}

	close(end[1]);
    close(f2);
                  
    // Execute the command (replace with execve or similar)
    if (execve("PATH", av[3], envp) == -1) // NULL is placeholder, replace accordingly
    {
        perror("execve failed");
        exit(EXIT_FAILURE); // Exit child process if execve fails
    }
}


void pipex(int f1, int f2, char **av, char **envp)
{
    int   end[2];
    int   status;
    pid_t child;
    pid_t parent;

    if (pipe(end) < 0)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    //child
    child = fork();
    if (child < 0)
    {
        perror("fork failed for child");
        exit(EXIT_FAILURE);
    }

    if (child == 0)
        child_process(f1, av, end, envp);  // Passing pipe and command
	
    //parent
    parent = fork();
    if (parent < 0)
    {
        perror("fork failed for parent");
        exit(EXIT_FAILURE);
    }

    if (parent == 0)
        parent_process(f2, av, end, envp);  // Pass the pipe and the command

    // Close both ends of the pipe
    if (close(end[0]) < 0 || close(end[1]) < 0)
    {
        perror("close failed");
        exit(EXIT_FAILURE);
    }

    // Wait for both children\parents to finish
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
