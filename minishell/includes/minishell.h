/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:53:11 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/06 20:14:33 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"

//include bunch of libraries I guess
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

//defines
# define STDERR 2

//structs
typedef struct s_sig
{
	int sigint;
    int sigquit;
}	t_sig;

typedef struct s_shell
{
    char **envp;
    char *input;
}	t_shell;


//global functions
void parse(t_shell *shell);

//sig.c
void handle_sigint(int code);
void handle_sigquit(int code);
void init_sig(void);

//builtins
void handle_echo(char **tokens);
void handle_cd(char **tokens);

extern t_sig sig;
#endif