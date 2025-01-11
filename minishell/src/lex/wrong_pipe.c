// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   wrong_pipe.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/11 10:44:57 by chlee2            #+#    #+#             */
// /*   Updated: 2025/01/11 13:39:09 by chlee2           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/minishell.h"

// void handle_wrong_pipes(char *input, t_shell *shell)
// {
// 	// Handle invalid sequences like `| |`, `|>` or `>` at start
// 	if (shell->last_token_type == 2 || shell->last_token_type == 3 || (token_count == 0 && current_token == NULL))
// 	{
// 			fprintf(stderr, "minishell: syntax error near unexpected token `%c`\n", c);
// 			free(input);
// 			exit(EXIT_FAILURE);
// 	}

// 	// Handle the pipe or redirection
// 	if (current_token)
// 	{
// 			tokens = ft_realloc(tokens, sizeof(char *) * (token_count + 2));
// 			if (!tokens)
// 			{
// 					perror("realloc");
// 					exit(EXIT_FAILURE);
// 			}
// 			tokens[token_count++] = current_token;
// 			tokens[token_count] = NULL;
// 			current_token = NULL;
// 	}

// 	current_token = str_append(NULL, c);
// 	if (c == '>' && input[i + 1] == '>')
// 	{
// 			current_token = str_append(current_token, input[++i]); // Handle `>>`
// 	}

// 	tokens = ft_realloc(tokens, sizeof(char *) * (token_count + 2));
// 	if (!tokens)
// 	{
// 			perror("realloc");
// 			exit(EXIT_FAILURE);
// 	}
// 	tokens[token_count++] = current_token;
// 	tokens[token_count] = NULL;
// 	current_token = NULL;

// 	shell->last_token_type = (c == '|') ? 2 : 3;
// }
