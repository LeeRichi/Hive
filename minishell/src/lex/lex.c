/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:23:08 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/09 23:35:06 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define WHITESPACE " \t\n"

char *str_append(char *str, char c)
{
    size_t len = str ? strlen(str) : 0;
    char *new_str = malloc(len + 2); // +1 for the new char, +1 for '\0'
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

char **tokenize_input(char *input)
{
    char **tokens = NULL;
    char *current_token = NULL;
    int token_count = 0;
    int in_single_quote = 0, in_double_quote = 0;

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
        }
        else if (strchr(WHITESPACE, c) && !in_single_quote && !in_double_quote)
        {
            if (current_token)
            {
                tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
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
        tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
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
