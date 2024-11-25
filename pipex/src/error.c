/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:34 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/25 18:47:45 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	tab[0] = NULL;
	free(tab);
}

static void message_check_print(char *err, char *av)
{
	if (av)
	{
		ft_putstr_fd(av, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static void	free_data(t_data *data)
{
	if (!data)
		return;
	if (data->f1 >= 0)
		close(data->f1);
	if (data->f2 >= 0)
		close(data->f2);
	if (data->end[0] >= 0)
		close(data->end[0]);
	if (data->end[1] >= 0)
		close(data->end[1]);
	free(data);
}

void	show_error(t_data *data, char *message, int err_code, char *av)
{
	if (av != NULL)
		message_check_print(message, av);
	free_data(data);
	exit(err_code);
}

void	show_error_for_sc(t_data *data, char *message, int err_code, char *av)
{
	if (av != NULL)
		message_check_print(message, av);
	free_data(data);
	free(av);
	exit(err_code);
}

