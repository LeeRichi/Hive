/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:45:12 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/08 14:28:03 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int handle_pwd(void)
{
    char path[PATH_MAX];
    
    if(getcwd(path, PATH_MAX))
    {
        ft_putendl_fd(path, 1);
        return (SUCCESS);
    }
    else
        return (ERROR);
}