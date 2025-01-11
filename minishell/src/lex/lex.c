/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:23:08 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/11 18:21:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *str_append(char *str, char c)
{
    size_t len = str ? strlen(str) : 0;
    char *new_str = malloc(len + 2);
    if (!new_str)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (str)
    {
        strcpy(new_str, str);
        free(str);
    }
    new_str[len] = c;
    new_str[len + 1] = '\0';
    return new_str;
}

char *get_env_value(const char *env_name)
{
	char *env_value;

	env_value = getenv(env_name);
	if (!env_value)
		return ("");
	return (ft_strdup(env_value));
}

char *handle_dollar_sign(char *s, int *index)
{
	char *env_name;
	char *result;
	int len;

	len = 0;
	(*index)++;
	while (ft_isalnum(s[*index]) || s[*index] == '_')
	{
		len++;
		(*index)++;
	}
	env_name = malloc(len + 1);
	if (!env_name)
		return (NULL);
	(*index) -= len;
	memcpy(env_name, s + *index, len);
	*index += len;
	env_name[len] = '\0';
	result = get_env_value(env_name);
	if (!result)
		return (NULL);
	free(env_name);
	return (result);
}

bool check_balanced_quotes(const char *input)
{
	int single_quotes = 0;
	int double_quotes = 0;
	int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '\\')
            i++;
        else if (input[i] == '\'' && double_quotes % 2 == 0)
            single_quotes++;
        else if (input[i] == '"' && single_quotes % 2 == 0)
            double_quotes++;
        i++;
    }

    return (single_quotes % 2 == 0 && double_quotes % 2 == 0);
}

void tokenize_input(char *input, t_shell *shell)
{
    char *current_token = NULL;
    int token_count = 0;
	int in_single_quote = 0;
	int in_double_quote = 0;
	char *env_value;
	int j;
    char c;

	//keep waiting for more inputs if quotes are not equal
	if (!check_balanced_quotes(input)) {
		while (1)
		{
			printf("$ ");
			char *additional_input = readline(NULL);
			if (additional_input) {
				input = str_append(input, '\n');
				// char *temp = input;
				input = ft_strjoin(input, additional_input);
				// free(temp);
				free(additional_input);
			}
		if (check_balanced_quotes(input))
			break;
		}
	}

    printf("last_token_type: %d\n", shell->last_token_type);

	int i = 0;
	while (input[i] != '\0')
    {
        c = input[i];

        if (c == '\'' && !in_double_quote)
        {
            in_single_quote = !in_single_quote;
        }
        else if (c == '"' && !in_single_quote)
        {
            in_double_quote = !in_double_quote;
            if (current_token == NULL)
            {
                shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
                if (!shell->tokens) {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                shell->tokens[token_count] = strdup("");
                shell->tokens[token_count + 1] = NULL;
                shell->last_token_type = 1;
            }
        }
		//handle dollar sign (but dont handle it in single quotes) and append
		else if (!in_single_quote && c == '$')
		{
			env_value = handle_dollar_sign(input, &i);
			j = 0;
			while (env_value[j])
			{
				current_token = str_append(current_token, env_value[j]);
				j++;
			}
			if (env_value && env_value[0] != '\0')
				free(env_value);
		}
		//handle wrong pipes and redirctions
		else if (strchr("|<>", c) && !in_single_quote && !in_double_quote)
		{
			handle_wrong_pipes(shell, current_token, token_count, c);
		}
		else if (strchr(WHITESPACE, c) && !in_single_quote && !in_double_quote)
        {
            if (current_token)
            {
                shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
                if (!shell->tokens)
                {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                shell->tokens[token_count++] = current_token;
                shell->tokens[token_count] = NULL;
                current_token = NULL;
            }
        }
        else
            current_token = str_append(current_token, c);
        i++;
    }

    if (current_token)
    {
        shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
        if (!shell->tokens)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        shell->tokens[token_count++] = current_token;
        shell->tokens[token_count] = NULL;
        shell->last_token_type = 1;
    }
}
