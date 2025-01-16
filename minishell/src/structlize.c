/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structlize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:27:51 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/16 15:17:11 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **ft_add_to_array(char **array, const char *new_element)
{
	int i;
	int len;

	len = 0;
	if (array)
    {
        while (array[len])
            len++;
    }
    char **new_array = malloc(sizeof(char *) * (len + 2));
    if (!new_array)
    {
        perror("malloc failed");
        return NULL;
    }
	i = 0;
	while (i < len)
	{
        new_array[i] = array[i];
		i++;
	}
	new_array[i] = ft_strdup(new_element);
    if (!new_array[i])
    {
        perror("strdup failed");
        free(new_array);
        return NULL;
    }
    new_array[i + 1] = NULL;
    if (array)
        free(array);
    return new_array;
}

void ft_nullize_struct(t_cmd *new_cmd)
{
    new_cmd->cmd_name = NULL;
    new_cmd->arg = NULL;
    new_cmd->infiles = NULL;
    new_cmd->outfiles = NULL;
    new_cmd->type = INPUT_REDIRECT; //deault
    new_cmd->pipe = 0;
    new_cmd->next = NULL;
}

void ft_add_redirection(char ***array, char *file)
{
    *array = ft_add_to_array(*array, file);
}

void handle_pipe(t_cmd **current_cmd, t_cmd **new_cmd, t_shell *shell)
{
    if (*current_cmd)
        (*current_cmd)->pipe = 1;
    *new_cmd = malloc(sizeof(t_cmd));
    if (!(*new_cmd))
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    ft_nullize_struct(*new_cmd);
    if (*current_cmd)
        (*current_cmd)->next = *new_cmd;
    else
        shell->cmds = *new_cmd;
    *current_cmd = *new_cmd;
}

void handle_redirection(t_cmd *current_cmd, char *operator, char *file)
{
    if (strcmp(operator, "<") == 0)
        ft_add_redirection(&current_cmd->infiles, file);
    else if (strcmp(operator, ">") == 0 || strcmp(operator, ">>") == 0)
        ft_add_redirection(&current_cmd->outfiles, file);
    else if (strcmp(operator, "<<") == 0)
    {
        ft_add_redirection(&current_cmd->infiles, file);
        current_cmd->type = HERE_DOC;
    }
}

void ft_structlize(t_shell *shell)
{
    int i = 0;
    t_cmd *current_cmd = NULL;
    t_cmd *new_cmd = NULL;

    while (shell->tokens[i])
    {
        if (current_cmd == NULL || strcmp(shell->tokens[i], "|") == 0)
        {
            handle_pipe(&current_cmd, &new_cmd, shell);
            if (strcmp(shell->tokens[i], "|") == 0)
            {
                i++;
                continue;
            }
        }
        if (strcmp(shell->tokens[i], "<") == 0 || strcmp(shell->tokens[i], ">") == 0 ||
            strcmp(shell->tokens[i], ">>") == 0 || strcmp(shell->tokens[i], "<<") == 0)
        {
			i++;
			handle_redirection(current_cmd, shell->tokens[i - 1], shell->tokens[i]);
		}
        else
        {
            if (current_cmd->cmd_name == NULL)
                current_cmd->cmd_name = strdup(shell->tokens[i]);
            else
                current_cmd->arg = ft_add_to_array(current_cmd->arg, shell->tokens[i]);
        }
        i++;
    }
}
