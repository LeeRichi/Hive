/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:28:12 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/14 19:28:53 by chlee2           ###   ########.fr       */
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
