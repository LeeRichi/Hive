/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/16 15:19:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_sig	g_sig;

static void shell_init(char **envp, t_shell *shell)
{
    shell->envp = envp;
    shell->input = NULL;
    shell->tokens = NULL;
    shell->token_count = 0;
    shell->current_index = 0;
    shell->exit_code = 0;
    shell->in_single_quote = 0;
    shell->in_double_quote = 0;
    shell->err_code = 0;
    shell->last_token_type = 0;
    shell->cmds = NULL;
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
