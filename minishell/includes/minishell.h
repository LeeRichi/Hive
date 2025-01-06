/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:53:11 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 17:34:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"

//include bunch of libraries I guess
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

//defines
# define STDERR 2

//structs
typedef struct s_sig
{
	int nbr;
}	t_sig;

typedef struct s_shell
{
    char **envp;
}	t_shell;


//global functions

#endif