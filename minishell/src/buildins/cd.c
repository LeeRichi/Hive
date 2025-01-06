/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:38:17 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 20:12:17 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void handle_cd(char **tokens)
{
    if (tokens[1])
    {
        if (chdir(tokens[1]) != 0)
            perror("cd");
    }
    else
    {
        char *home = getenv("HOME");
        if (home)
            chdir(home);
        else
            printf("HOME not set.\n");
    }
}
