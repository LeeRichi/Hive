/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:16:25 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/14 20:03:12 by chlee2           ###   ########.fr       */
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

	g_sig.sigquit = 1;
}

void init_sig(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	// g_sig.pid = 0;
	// g_sig.exit_status = 0;
}
