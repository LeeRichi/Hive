/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:54:11 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/15 17:01:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *extract_delimiter(char *input, int *i)
{
    int start = *i + 2;  // Skip past the `<<`
    while (input[start] && strchr(WHITESPACE, input[start]))  // Skip any leading spaces
        start++;

    int end = start;
    while (input[end] && !strchr(WHITESPACE, input[end]))  // Find the end of the delimiter
        end++;

    // Allocate memory for the delimiter string
    char *delimiter = ft_substr(input, start, end - start);
    *i = end - 1;  // Move the index after the delimiter


    printf("delimiter: %s\n", delimiter);

    return delimiter;
}

void handle_heredoc(t_shell *shell, char *delimiter)
{
    char *line;
    int pipe_fd[2];

		(void)shell;

		// Create a pipe to store the heredoc input
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("> ");
        line = readline(NULL);

        if (!line) // EOF reached //?
        {
            printf("minishell: warning: here-document delimited by end-of-file\n");
            break;
        }

        // Check if the delimiter is reached
        if (ft_strcmp(line, delimiter) == 0)
        {
            free(line);
            break;
        }

        // Write the input line to the pipe
        write(pipe_fd[1], line, strlen(line));
        write(pipe_fd[1], "\n", 1); // Add a newline for each line
        free(line);
    }

    close(pipe_fd[1]); // Close the write end of the pipe

    // Redirect pipe read end to stdin
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]); // Close the read end after redirection
}
