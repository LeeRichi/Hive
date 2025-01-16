/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:53:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/16 15:12:56 by chlee2           ###   ########.fr       */
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

        // Print input files if any
        if (cmd->infiles)
        {
            printf("Input Files: ");
            for (int i = 0; cmd->infiles[i]; i++)
                printf("%s ", cmd->infiles[i]);
            printf("\n");
        }

        // Print output files if any
        if (cmd->outfiles)
        {
            printf("Output Files: ");
            for (int i = 0; cmd->outfiles[i]; i++)
                printf("%s ", cmd->outfiles[i]);
            printf("\n");
        }

        // Print redirection type if set
        if (cmd->type)
        {
            if (cmd->type == INPUT_REDIRECT)
                printf("Redirection Type: INPUT_REDIRECT\n");
            else if (cmd->type == OUTPUT_REDIRECT)
                printf("Redirection Type: OUTPUT_REDIRECT\n");
            else if (cmd->type == APPEND_REDIRECT)
                printf("Redirection Type: APPEND_REDIRECT\n");
            else if (cmd->type == HERE_DOC)
                printf("Redirection Type: HERE_DOC\n");
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
