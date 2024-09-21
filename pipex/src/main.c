/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/21 13:00:00 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_one(int f1, char *cmd1, int *end)
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
    if (execve(cmd1, NULL, NULL) == -1) // NULL is placeholder, replace accordingly
    {
        perror("execve failed");
        exit(EXIT_FAILURE); // Exit child process if execve fails
    }
}


void pipex(int f1, int f2, char **cmd, char **envp)
{
    int   end[2];
    int   status;
    pid_t child1;
    pid_t child2;

    // Create a pipe
    if (pipe(end) < 0)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    child1 = fork();
    if (child1 < 0)
    {
        perror("fork failed for child1");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0)
        child_one(f1, cmd[2], end);  // Passing pipe and command
		
    child2 = fork();
    if (child2 < 0)
    {
        perror("fork failed for child2");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0)
        child_two(f2, cmd[3], end);  // Pass the pipe and the command

    // Close both ends of the pipe in the parent process
    if (close(end[0]) < 0 || close(end[1]) < 0)
    {
        perror("close failed");
        exit(EXIT_FAILURE);
    }

    // Wait for both children to finish
    waitpid(child1, &status, 0);  // Handle the return value if needed
    waitpid(child2, &status, 0);  // Handle the return value if needed
}


int main(int ac, char **av, char **envp)
{
	int f1;
	int f2;

	//in subject says: It must take 4 arguments.
	//below is an example
	//$> ./pipex infile "ls -l" "wc -l" outfile
	if (ac != 5)
	{
		ft_printf("Needs exact 4 arguments.\n");
		return (EXIT_FAILURE);
	}
	else
	{
		f1 = open(av[1], O_RDONLY);
     	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		// pipex(f1, f2, av[2], av[3]);
		pipex(f1, f2, av, envp);
     	return (0);
	}
}
