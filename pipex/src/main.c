/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:41:41 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 17:08:27 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av)
{
	(void)av;

	//in subject says: It must take 4 arguments.
	//below is an example
	//$> ./pipex infile "ls -l" "wc -l" outfile
	if (ac != 5)
	{
		ft_printf("Needs exact 4 arguments.\n");
		return (EXIT_FAILURE);
	}
	


}
