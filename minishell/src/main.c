/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/08 17:16:51 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//global signal
t_sig sig;

//think what you need in a shell
void shell_init(char **av, char **envp, t_shell *shell)
{
	(void)av;
    shell = (t_shell *)malloc(sizeof(t_shell));
    if (!shell)
    {
        perror("Failed to initialize shell\n");
        exit(EXIT_FAILURE);
    }
    shell->envp = envp;
    shell->input = NULL;

	//print something if it's needed
}

void ft_free_all(t_shell *shell)
{
	if (shell->input)
    {
        free(shell->input);
        shell->input = NULL;
    }

	//free linked list?

	//might as well free envp?
	// if (shell->envp)
    // {
    //     for (int i = 0; shell->envp[i] != NULL; i++)
    //     {
    //         free(shell->envp[i]);
    //     }
    //     free(shell->envp);
    // }
}

int	main(int ac, char **av, char **envp)
{
	t_shell shell;

	if (ac != 1)
	{
		printf("We only handle 1 comment.\n");
		exit(EXIT_FAILURE);
	}
	init_sig();
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, &handle_sigquit);

	shell_init(av, envp, &shell);
	//exec minishell
	while (1)
	{
		shell.input = readline("> ");
        if (!shell.input)
        {
            printf("exit\n");
            break;
        }
        if (shell.input)
            add_history(shell.input);
		//parse
		parse(&shell);
		//exec //later
		// execute(&shell);
	}
	ft_free_all(&shell);
	return(shell.exit_code);
}
