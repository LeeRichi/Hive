/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:44:57 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/11 19:11:58 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void handle_wrong_pipes(t_shell *shell, char **current_token, int *token_count, char c)
{
    int i = 0;

    printf("*current_token: %s\n", *current_token);
    // printf("token_count: %d\n", token_count);
    printf("last_token_type: %d\n", shell->last_token_type);

	// Handle invalid sequences like `| |`, `|>` or `>` at start
	// if (shell->last_token_type == 2 || shell->last_token_type == 3 || (token_count == 0 && *current_token == NULL))
	// {
    //     printf("minishell: syntax error near unexpected token `%c`\n", c);
    //     // free(shell->input);
    //     // exit(EXIT_FAILURE);
	// }

	// Handle the pipe or redirection
	if (*current_token)
	{
        shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * ((*token_count) + 2));
        if (!shell->tokens)
        {
            ft_printf("wait for more input\n");
            // perror("realloc");
            // exit(EXIT_FAILURE);
        }
        shell->tokens[(*token_count)++] = *current_token;
        shell->tokens[*token_count] = NULL;
        *current_token = NULL;
	}

	*current_token = str_append(NULL, c);
	if (c == '>' && shell->input[i + 1] == '>')
	{
        *current_token = str_append(*current_token, shell->input[++i]); // Handle `>>`
	}

	shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * ((*token_count) + 2));
	if (!shell->tokens)
	{
        ft_printf("wait for more input\n");
        // perror("realloc");
        // exit(EXIT_FAILURE);
	}
	shell->tokens[(*token_count)++] = *current_token;
	shell->tokens[*token_count] = NULL;
	*current_token = NULL;

	shell->last_token_type = (c == '|') ? 2 : 3;
}
