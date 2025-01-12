/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:23:08 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/12 19:05:27 by chlee2           ###   ########.fr       */
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
	int type_flag = 0;

	// Keep waiting for more inputs if quotes are not balanced
    while (!check_balanced_quotes(input))
    {
        printf("$ ");
        char *additional_input = readline(NULL);
        if (!additional_input)
        {
            fprintf(stderr, "minishell: unexpected EOF while looking for matching quotes\n");
            free(input);
            exit(EXIT_FAILURE);
        }
        input = str_append(input, '\n');
        input = ft_strjoin(input, additional_input);
        free(additional_input);
    }

    int i = 0;
    while (input[i] != '\0')
    {
        c = input[i];
        if (c == '\'' && !in_double_quote)
            in_single_quote = !in_single_quote;
        else if (c == '"' && !in_single_quote)
        {
            in_double_quote = !in_double_quote;
            if (current_token == NULL)
            {
                shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
                if (!shell->tokens)
                {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                shell->tokens[token_count] = strdup("");
                shell->tokens[token_count + 1] = NULL;
                shell->last_token_type = 1;
            }
        }
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
        else if (strchr("|<>", c) && !in_single_quote && !in_double_quote)
        {
            handle_wrong_pipes(shell, &current_token, &token_count, c);
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
        {
            current_token = str_append(current_token, c);
        }
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
        shell->tokens[token_count] = current_token;
        shell->tokens[token_count + 1] = NULL;
        shell->last_token_type = 1;
    }

    // Handle incomplete commands like `|` or `<`
    while (shell->last_token_type == 2 || shell->last_token_type == 3)
    {
        printf("> ");
        char *additional_input = readline(NULL);
        if (!additional_input)
        {
            fprintf(stderr, "minishell: unexpected EOF after `%c`\n",
				shell->last_token_type == 2 ? '|' : '<');
            free(input);
            exit(EXIT_FAILURE);
        }
        // input = str_append(input, '\n');
        // printf("additional_input: %s\n", additional_input);
        additional_input = ft_strjoin(" ", additional_input);
        input = ft_strjoin(input, additional_input);
        // printf("new_input: %s\n", input);

        // Reset parsing state for the additional input
        // current_token = NULL;
        // token_count = 0;
        // in_single_quote = 0;
        // in_double_quote = 0;
        i = 0;
        // Re-parse the new input
        while (additional_input[i] != '\0')
        {
        	printf("additional_input[i]: %c\n", additional_input[i]);
            c = additional_input[i];
            if (c == '\'' && !in_double_quote)
            {
                in_single_quote = !in_single_quote;
            }
            else if (c == '"' && !in_single_quote)
            {
                in_double_quote = !in_double_quote;
            }
            else if (!in_single_quote && c == '$')
            {
                env_value = handle_dollar_sign(additional_input, &i);
                j = 0;
                while (env_value[j])
                {
                    current_token = str_append(current_token, env_value[j]);
                    j++;
                }
                if (env_value && env_value[0] != '\0')
                    free(env_value);
            }
            else if (strchr("|<>", c) && !in_single_quote && !in_double_quote)
            {
                handle_wrong_pipes(shell, &current_token, &token_count, c);
            }
            else if (strchr(WHITESPACE, c) && !in_single_quote && !in_double_quote)
            {
				printf("test\n");
				if (current_token)
				{
					printf("test2\n");
                    shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
                    if (!shell->tokens)
                    {
                        perror("realloc");
                        exit(EXIT_FAILURE);
                    }
                    shell->tokens[token_count] = current_token;
                    shell->tokens[token_count + 1] = NULL;
                    current_token = NULL;
                }
            }
            else
            {
				printf("add: %c\n", additional_input[i]);
                current_token = str_append(current_token, c);
            }
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
			shell->tokens[token_count] = current_token;
			shell->tokens[token_count + 1] = NULL;
			shell->last_token_type = 1;
		}
    }
}
