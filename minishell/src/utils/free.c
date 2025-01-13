/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:20:26 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/13 23:34:38 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	//temp
	*tokens = NULL;
}

void clear_tokens(t_shell *shell)
{
    if (shell->tokens)
    {
        for (int i = 0; shell->tokens[i]; i++)
        {
            free(shell->tokens[i]);
        }
        free(shell->tokens);
        shell->tokens = NULL;
    }
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
