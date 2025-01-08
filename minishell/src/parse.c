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
            perror(tokens[0]);
            exit(1);
        }
    }
    else
    {
        // Parent process: wait for child to finish
        wait(NULL);
    }
}

//temp
void print_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i])
    {
        printf("Token %d: %s\n", i, tokens[i]);
        i++;
    }
}

void parse(t_shell *shell)
{
    char *input = shell->input;  // Assuming `input` is set in the shell struct
    char **tokens;

    tokens = ft_split(input, ' ');
    if (!tokens)
        printf("split failed.\n");

    print_tokens(tokens);

    // Check for built-in commands (example: "cd", "exit")
    if (tokens[0] != NULL)
    {
        if (tokens[0] != NULL)
        {
            if (strcmp(tokens[0], "echo") == 0)
                handle_echo(tokens);
            else if (strcmp(tokens[0], "cd") == 0)
                handle_cd(tokens);
            else if (strcmp(tokens[0], "pwd") == 0)
                handle_pwd();
            // else if (strcmp(tokens[0], "env") == 0)
            //     handle_env(shell->envp); // Pass environment variables
            else if (strcmp(tokens[0], "exit") == 0)
                handle_exit(shell, tokens);
            // else if (strcmp(tokens[0], "unset") == 0)
            //     handle_unset(tokens);
            // else if (strcmp(tokens[0], "echo") == 0)
            //     handle_echo(tokens);
            // else if (strcmp(tokens[0], "export") == 0)
            //     handle_export(tokens);
            else
                execute_external_command(tokens);
        }
    }

    //might delete depends how I free_all?
    free_tokens(tokens);
}
