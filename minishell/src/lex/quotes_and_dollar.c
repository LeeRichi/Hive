/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:25:01 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/14 19:40:19 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void handle_unbalanced_quotes(char **input)
{
    while (!check_balanced_quotes(*input))
    {
        printf("$ ");
        char *additional_input = readline(NULL);
        if (!additional_input)
        {
            fprintf(stderr, "minishell: unexpected EOF while looking for matching quotes\n");
            free(*input);
            exit(EXIT_FAILURE);
        }
        char *new_input = ft_strjoin(*input, additional_input);
        free(*input);
        free(additional_input);
        *input = new_input;
    }
}

