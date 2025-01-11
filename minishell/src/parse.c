#include "../includes/minishell.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void free_tokens(char **tokens)
{
    int i = 0;

	//temp
	if (!tokens)
		return ;
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
		printf("i: %d\n", i);
		i++;
	}
}

void parse(t_shell *shell)
{
    char *input = shell->input;
	//init (again? not sure why? without this will cause seg.f)
	shell->tokens = NULL;

	tokenize_input(input, shell);
	//unnes
	// if (!shell->tokens)
    //     printf("tokenize_input failed by returning NULL.\n");

	//token print
	if(shell->tokens)
		print_tokens(shell->tokens);

    // Check for built-in commands (example: "cd", "exit")
    if (shell->tokens && shell->tokens[0] != NULL)
    {
        if (strcmp(shell->tokens[0], "echo") == 0)
            handle_echo(shell->tokens);
        else if (strcmp(shell->tokens[0], "cd") == 0)
            handle_cd(shell->tokens);
        else if (strcmp(shell->tokens[0], "pwd") == 0)
            handle_pwd();
        else if (strcmp(shell->tokens[0], "exit") == 0)
            handle_exit(shell, shell->tokens);
        // else if (strcmp(shell->tokens[0], "env") == 0)
        //     handle_env(shell->envp); // Pass environment variables
        // else if (strcmp(shell->tokens[0], "unset") == 0)
        //     handle_unset(shell->tokens);
        // else if (strcmp(shell->tokens[0], "export") == 0)
        //     handle_export(shell->tokens);

        else
            execute_external_command(shell->tokens);
    }
    //might delete depends how I free_all?
    // if (shell->tokens)
    //     free_shell->tokens(shell->tokens);
}
