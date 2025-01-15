/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/15 17:15:57 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_sig	g_sig;

static void	shell_init(char **envp, t_shell *shell)
{
	shell->envp = envp;
	shell->input = NULL;
	shell->tokens = NULL;
	shell->last_token_type = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)av;
	if (ac != 1)
	{
		printf("We only handle 1 comment.\n");
		exit(EXIT_FAILURE);
	}
	init_sig();
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, &handle_sigquit);
	shell_init(envp, &shell);
	while (1)
	{
		shell.input = readline("$ ");
		if (shell.input)
			add_history(shell.input);
		parse(&shell);
		// execute(&shell);
	}
	ft_free_all(&shell);
	return (shell.exit_code);
}
