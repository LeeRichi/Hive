/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:23:08 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/10 20:55:09 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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
	int j;
	int len;

	len = 0;
	(*index)++;
	while (isalnum(s[*index]) || s[*index] == '_')
	{
		len++;
		(*index)++;
	}
	env_name = malloc(len + 1);
	if (!env_name)
		return (NULL);
	j = 0;
	while (isalnum(s[*index]) || s[*index] == '_')
	{
		env_name[j++] = s[*index++];
		(*index)++;
	}
	env_name[j] = '\0';
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

char **tokenize_input(char *input)
{
    char **tokens = NULL;
    char *current_token = NULL;
    int token_count = 0;
    int in_single_quote = 0, in_double_quote = 0;
	char *env_value;
	int j;

    //but what if i got "" which is an empty string

    //keep waiting for more inputs if quotes are not equal
	if (!check_balanced_quotes(input)) {
		while (1) {
			printf("> ");
			char *additional_input = readline(NULL);
			if (additional_input) {
				input = str_append(input, '\n');
				char *temp = input;
				input = ft_strjoin(input, additional_input);
				free(temp);
				free(additional_input);
			}
		if (check_balanced_quotes(input))
			break;
    	}
	}

	int i = 0;
	while (input[i] != '\0')
    {
        char c = input[i];

        if (c == '\'' && !in_double_quote)
        {
            in_single_quote = !in_single_quote;
        }
        else if (c == '"' && !in_single_quote)
        {
            in_double_quote = !in_double_quote;
            if (current_token == NULL) 
            {
                tokens = ft_realloc(tokens, sizeof(char *) * (token_count + 2));
                if (!tokens) {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                tokens[token_count] = strdup("");
                tokens[token_count + 1] = NULL;
            }
        }
		else if (in_double_quote && c == '$')
		{
			env_value = handle_dollar_sign(input, &i);
			j = 0;
			while (env_value[j])
			{
				current_token = str_append(current_token, env_value[j]);
				j++;
			}
			free(env_value);
		}
		else if (strchr(WHITESPACE, c) && !in_single_quote && !in_double_quote)
        {
            if (current_token)
            {
                tokens = ft_realloc(tokens, sizeof(char *) * (token_count + 2));
                if (!tokens)
                {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                tokens[token_count++] = current_token;
                tokens[token_count] = NULL;
                current_token = NULL;
            }
        }
        else
            current_token = str_append(current_token, c);
        i++;
    }

    if (current_token)
    {
        tokens = ft_realloc(tokens, sizeof(char *) * (token_count + 2));
        if (!tokens)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tokens[token_count++] = current_token;
        tokens[token_count] = NULL;
    }

    return tokens;
}
