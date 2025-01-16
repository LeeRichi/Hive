/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:53:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/16 20:50:55 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//this file does not need to be pushed
//only for testing purpose

//or fix the norm in order to push

void print_tokens(char **tokens)
{
    int i;

    i = 0;
    while (tokens[i])
    {
        printf("Token %d: %s\n", i, tokens[i]);
		i++;
	}
}

static const char *get_redirection_type_string(int type)
{
    if (type == INPUT_REDIRECT)
        return "INPUT_REDIRECT";
    if (type == OUTPUT_REDIRECT)
        return "OUTPUT_REDIRECT";
    if (type == APPEND_REDIRECT)
        return "APPEND_REDIRECT";
    if (type == HERE_DOC)
        return "HERE_DOC";
    return "UNKNOWN_TYPE";
}

void print_cmd_struct(t_cmd *cmd)
{
    int command_index = 1;  // To track the command index in the linked list
    while (cmd)
    {
        printf("Command %d:\n", command_index++);
        printf("Command Name: %s\n", cmd->cmd_name ? cmd->cmd_name : "NULL");

        // Print arguments if any
        if (cmd->arg)
        {
            printf("Arguments: ");
            for (int i = 0; cmd->arg[i]; i++)
                printf("%s ", cmd->arg[i]);
            printf("\n");
        }
        int file_counter = 0;
        // Print input files if any
        if (cmd->infiles)
        {
            printf("Input Files: ");
            for (int i = 0; cmd->infiles[i]; i++)
            {
                printf("%s ", cmd->infiles[i]);
                file_counter++;
            }
            printf("\n");
        }

        // Print output files if any
        if (cmd->outfiles)
        {
            printf("Output Files: ");
            for (int i = 0; cmd->outfiles[i]; i++)
            {
                printf("%s ", cmd->outfiles[i]);
                file_counter++;
            }
            printf("\n");
        }


        //cat < 1 > 2 >> 3
        if (cmd->type)
        {
            printf("Types: \n");
            for (int i = 0; i < file_counter; i++)
                printf("%s \n", get_redirection_type_string(cmd->type[i]));
            printf("\n");
        }

        // Print pipe flag
        printf("Pipe: %d\n", cmd->pipe);

        // Print the "next" pointer information to show it's a linked list
        if (cmd->next)
            printf("Next Command: %p\n", (void *)cmd->next);
        else
            printf("Next Command: NULL\n");

        // Move to the next command in the list
        cmd = cmd->next;
        printf("\n");  // Adding a newline between commands for better readability
    }
}
