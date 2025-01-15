/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:53:11 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/15 14:08:31 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

//defines
# define STDERR 2

# define SUCCESS 0
# define ERROR 1
# define NONE_NUMERIC_EXIT_CODE 255
# define WHITESPACE " \t\n"

//structs
typedef struct s_sig
{
	int sigint;
  	int sigquit;
}	t_sig;

typedef enum e_token_type {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT
} t_token_type;

//this is doubly linked list struct //not used yet //pending
typedef struct s_token
{
 char   *str;
 char   *type;
 struct s_token *prev;
 struct s_token *next;
} t_token;

typedef struct s_shell
{
    char	**envp;
    char    *input;
	int 	current_index;
	int 	exit_code;
	char    **tokens; //might need to change tpye to custom linked list??
    int		last_token_type; //can chane to enum?
	int		token_count;
	int		in_single_quote;
    int		in_double_quote;
} t_shell;


//global functions
void parse(t_shell *shell);

//sig.c
void handle_sigint(int code);
void handle_sigquit(int code);
void init_sig(void);

//builtins
void handle_echo(char **tokens);
void handle_cd(char **tokens);
int handle_pwd(void);
void handle_exit(t_shell *shell, char **tokens);

//lex
void tokenize_input(char *input, t_shell *shell);
char *str_append(char *str, char c);
//lex/wrong_pipe.c
int empty_pipe_checker(char *input, t_shell *shell);
void handle_wrong_pipes(t_shell *shell, char **current_token, int *token_count, char c);
//lex/wrong_quotes.c
char *handle_dollar_sign(char *s, int *index);
bool check_balanced_quotes(const char *input);
void handle_unbalanced_quotes(char **input);

//lex/lex_helper.c
char *str_append(char *str, char c);
char *get_env_value(const char *env_name);
int ft_arraylen(char **tokens);
int ft_start_with(char *str, char c);
int ft_end_with(char *str, char c);

//utils
//free.c
void free_tokens(char **tokens);
void clear_tokens(t_shell *shell);
void ft_free_all(t_shell *shell);
//print.c
void print_tokens(char **tokens);

//lex/heredoc.c
void handle_heredoc(t_shell *shell, char *delimiter);

extern t_sig g_sig;
#endif
