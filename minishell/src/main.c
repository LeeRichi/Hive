/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/07 20:43:07 by chlee2           ###   ########.fr       */
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
    (shell)->envp = envp;
    (shell)->input = NULL;

	//print something if it's needed
}

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	(void)av;
	char *input;
	t_shell *shell;

	shell = NULL;

	if (ac != 1)
	{
		printf("We only handle 1 comment.\n");
		exit(EXIT_FAILURE);
	}
	init_sig();
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, &handle_sigquit);

	shell_init(av, envp, shell);
	//exec minishell
	while (1)
	{
		input = readline("> ");
        if (!input)
        {
            printf("exit\n");
            break;
        }
        if (*input)
            add_history(input);
		//parse
		shell->input = input;
		parse(shell);
		
    	free(input);
	}
	free(shell);
}
