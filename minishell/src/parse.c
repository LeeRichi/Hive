#include "../includes/minishell.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void free_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

void execute_external_command(char **tokens)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        // Child process: execute external command
        if (execvp(tokens[0], tokens) == -1)
        {
            perror("execvp");
            exit(1);
        }
    }
    else
    {
        // Parent process: wait for child to finish
        wait(NULL);
    }
}

void parse(t_shell *shell)
{
    char *input = shell->input;  // Assuming `input` is set in the shell struct
    char **tokens;
    // int i = 0;

    tokens = ft_split(input, ' ');
    if (!tokens)
    {
        printf("split failed.\n");
    }
    // Check for built-in commands (example: "cd", "exit")
    if (tokens[0] != NULL)
    {
        if (strcmp(tokens[0], "cd") == 0)
        {
            if (tokens[1])
            {
                if (chdir(tokens[1]) != 0)
                    perror("cd");
            }
            else
            {
                // Default behavior: change to the home directory
                char *home = getenv("HOME");
                if (home)
                    chdir(home);
                else
                    printf("HOME not set.\n");
            }
        }
        else if (strcmp(tokens[0], "exit") == 0)
        {
            // Exit the shell
            free_tokens(tokens);
            exit(0);
        }
        else
        {
            // Handle external commands by forking and exec'ing
            execute_external_command(tokens);
        }
    }

    free_tokens(tokens);
}
