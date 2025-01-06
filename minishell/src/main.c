/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 18:04:06 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
# include <readline/readline.h>
# include <stdio.h>
# include <signal.h>
#include <stdlib.h>

t_sig *sig;

//think what you need in a shell
void shell_init(char **av, char **envp, t_shell **shell)
{
	(void)av;
    *shell = (t_shell *)malloc(sizeof(t_shell));
    if (!*shell)
    {
        perror("Failed to initialize shell\n");
        exit(EXIT_FAILURE);
    }
    (*shell)->envp = envp;
    (*shell)->input = NULL;

	//print something if it's needed
}

//to handle ctrl+c //display a new lie
void handle_sigint(int sig)
{
    (void)sig;
    printf("\n");
	ft_putstr_fd("> ", STDERR);
}

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	(void)av;
	char *input;
	t_shell *shell;

	if (ac != 1)
	{
		printf("We only handle 1 comment.\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	shell_init(av, envp, &shell);
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
