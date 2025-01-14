/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:44:57 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/14 23:47:42 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void handle_token(t_shell *shell, char **current_token, int *token_count)
{
    if (*current_token)
    {
        shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * ((*token_count) + 2));
        if (!shell->tokens)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        shell->tokens[(*token_count)++] = *current_token;
        shell->tokens[*token_count] = NULL;
        *current_token = NULL;
    }
}

void handle_wrong_pipes(t_shell *shell, char **current_token, int *token_count, char c)
{
    int i = 0;

	// Handle the pipe or redirection
	handle_token(shell, current_token, token_count);

	*current_token = str_append(NULL, c);

	if (c == '>' && shell->input[i + 1] == '>')
        *current_token = str_append(*current_token, shell->input[++i]);

	shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * ((*token_count) + 2));
	if (!shell->tokens)
		printf("wait for more input\n");
	shell->tokens[(*token_count)++] = *current_token;
	shell->tokens[*token_count] = NULL;
	*current_token = NULL;

	shell->last_token_type = (c == '|') ? 2 : 3;
}
