/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:28:12 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/15 16:11:41 by chlee2           ###   ########.fr       */
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
    {
        len++;
    }
	return (len);
}

int ft_start_with(char *str, char c)
{
    int i = 0;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        	i++;
        if (str[i] != c)
            return (0);
		else
			return (1);
		// Check for incomplete operators like '|'
        // if (str[i] == '|' || str[i] == '&' || str[i] == '<' || str[i] == '>')
        //     return (1);
        // // Check for unclosed quotes
        // if (str[i] == '\'' || str[i] == '\"')
        //     return (1);
        i++;
    }
    return (0);
}

int ft_end_with(char *str, char c)
{
    // int i = 0;
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		len--;
		while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
			len--;
        if (str[len] == c)
			return (1);
		else
			return (0);
		// //>> or << //maybe no need
        // if ((c == '<' && str[len - 1] == '<' ) || (c == '>' && str[len - 1] == '>'))
        //     return (1);
        // // Check for unclosed quotes //not sure
        // if (str[i] == '\'' || str[i] == '\"')
        //     return (1);
        len--;
    }
    return (0);
}
