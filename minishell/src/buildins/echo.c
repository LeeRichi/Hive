/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:45:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 20:19:11 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void handle_echo(char **tokens)
{
    int i = 1;
    int newline = 1;

    if (tokens[1] && strcmp(tokens[1], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    while (tokens[i])
    {
        printf("%s", tokens[i]);
        if (tokens[i + 1])
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
}