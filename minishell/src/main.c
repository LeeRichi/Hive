/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 14:47:18 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
# include <readline/readline.h>


// void shell_init(char **av, char **envp)
// {
//     t_shell *shell;
// }

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	(void)av;
	char *inputs;
	if (ac != 1)
	{
		ft_printf("We only handle 1 comment.\n");
		exit(EXIT_FAILURE);
	}
	//exec minishell
	while (1)
	{
		inputs = readline("> ");
        if (!inputs) // Handle EOF (Ctrl+D)
        {
            ft_printf("exit\n");
            break;
        }
        // if (*inputs) // Add non-empty input to history
        //     add_history(inputs);

        // Parse and execute the command here (to be implemented)
        ft_printf("Command: %s\n", inputs); // Placeholder for debugging
        
        // Free the input string
        free(inputs);
	}
}
