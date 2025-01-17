#include "../includes/minishell.h"

//exe part
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

void parse(t_shell *shell)
{
	tokenize_input(shell->input, shell);

	// print_tokens(shell->tokens);
	if (!shell->err_code)
		ft_structlize(shell);

	print_cmd_struct(shell->cmds);

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
        // else
        //     execute_external_command(shell->tokens);
    }
    //might delete depends how I free_all?
    // if (shell->tokens)
    //     free_shell->tokens(shell->tokens);
}
