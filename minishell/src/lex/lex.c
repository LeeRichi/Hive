/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:23:08 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/13 23:34:47 by chlee2           ###   ########.fr       */
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

int ft_arraylen(char **tokens)
{
	int len;

	len = 0;
	if (!tokens)
        return (0);
    while (tokens[len] != NULL)
        len++;
	return (len);
}

void parse_input_fragment(char *input, t_shell *shell, int *in_single_quote, int *in_double_quote)
{
    char *current_token = NULL;
    char *env_value;
    int token_count = shell->tokens ? ft_arraylen(shell->tokens) : 0;
    int i = 0, j;
    char c;

    while (input[i] != '\0')
    {
        c = input[i];
        if (c == '\'' && !(*in_double_quote))
            *in_single_quote = !(*in_single_quote);
        else if (c == '"' && !(*in_single_quote))
            *in_double_quote = !(*in_double_quote);
        else if (!(*in_single_quote) && c == '$')
        {
            env_value = handle_dollar_sign(input, &i);
            j = 0;
            while (env_value[j])
                current_token = str_append(current_token, env_value[j++]);
            free(env_value);
        }
        else if (strchr("|<>", c) && !(*in_single_quote) && !(*in_double_quote))
        {
            handle_wrong_pipes(shell, &current_token, &token_count, c);
        }
        else if (strchr(WHITESPACE, c) && !(*in_single_quote) && !(*in_double_quote))
        {
            if (current_token)
            {
                shell->tokens = ft_realloc(shell->tokens, sizeof(char *) * (token_count + 2));
                shell->tokens[token_count++] = current_token;
                shell->tokens[token_count] = NULL;
                current_token = NULL;
				shell->last_token_type = 1;
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
        shell->tokens[token_count++] = current_token;
        shell->tokens[token_count] = NULL;
		shell->last_token_type = 1;
    }

	// print_tokens(shell->tokens);
}

void tokenize_input(char *input, t_shell *shell)
{
    int in_single_quote = 0;
    int in_double_quote = 0;

	clear_tokens(shell);

	//this does not work
	// free_tokens(&shell->tokens);

	while (!check_balanced_quotes(input))
	{
        printf("> ");
        char *additional_input = readline(NULL);
        if (!additional_input)
        {
            fprintf(stderr, "minishell: unexpected EOF while looking for matching quotes\n");
            free(input);
            exit(EXIT_FAILURE);
        }
        input = ft_strjoin(input, additional_input);
        free(additional_input);
    }

    parse_input_fragment(input, shell, &in_single_quote, &in_double_quote);

    // Handle incomplete commands
	while (shell->last_token_type == 2 || shell->last_token_type == 3)
	{
        printf("$ ");
        char *additional_input = readline(NULL);
        if (!additional_input)
        {
            fprintf(stderr, "minishell: unexpected EOF after `%c`\n",
				shell->last_token_type == 2 ? '|' : '<');
            free(input);
            exit(EXIT_FAILURE);
        }

        input = ft_strjoin(input, " ");
        input = ft_strjoin(input, additional_input);
		parse_input_fragment(additional_input, shell, &in_single_quote, &in_double_quote);
		free(additional_input);
    }

	shell->last_token_type = 0;

	free(input);
}

