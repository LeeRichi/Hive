/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:16:25 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/11 17:55:06 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

//to handle ctrl+c //display a new lie
void handle_sigint(int code)
{
	(void)code;
	printf("\n");
	ft_putstr_fd("$ ", STDERR);
}

//ctrl+\/
void handle_sigquit(int code)
{

	(void)code;
	// char *err_code;

	signal(SIGQUIT, SIG_IGN);
	// err_code = ft_itoa(code);

	sig.sigquit = 1;
}

//void casue sig is globall anyway
void init_sig(void)
{
    //no need?
	// sig = (t_sig *)malloc(sizeof(t_sig));
    // if (!sig)
    // {
    //     perror("Failed to allocate memory for sig");
    //     exit(EXIT_FAILURE);
    // }
	sig.sigint = 0;
	sig.sigquit = 0;
// 	sig.pid = 0;
// 	sig.exit_status = 0;
}
