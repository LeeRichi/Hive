/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:11:39 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/18 17:32:05 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**split_command(char *cmd, t_data *data)
{
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		show_error(data, "s_cmd split malloc failed.\n", EXIT_FAILURE);
	return (s_cmd);
}

static char	**get_paths(char **envp, t_data *data)
{
	int		i;
	char	**all_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_path = ft_split(envp[i] + 5, ':');
			if (!all_path)
				show_error(data, "all_path split failed.\n", EXIT_FAILURE);
			return (all_path);
		}
		i++;
	}
	return (NULL);
}

static char	*build_and_check_path(char *dir, char *cmd)
{
	char	*one_path;
	char	*full_path;

	one_path = ft_strjoin(dir, "/");
	if (!one_path)
		return (NULL);
	full_path = ft_strjoin(one_path, cmd);
	free(one_path);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_path(t_data *data, char *cmd, char **envp)
{
	char	**s_cmd;
	char	**all_path;
	char	*full_path;
	int		i;

	full_path = NULL;
	s_cmd = split_command(cmd, data);
	all_path = get_paths(envp, data);
	if (!all_path)
	{
		ft_free_tab(s_cmd);
		show_error(data, "No PATH found.", EXIT_FAILURE);
	}
	i = -1;
	while (all_path[++i])
	{
		full_path = build_and_check_path(all_path[i], s_cmd[0]);
		if (full_path)
			break ;
	}
	ft_free_tab(all_path);
	ft_free_tab(s_cmd);
	if (!full_path)
		show_error(data, "command not found: cmd[0]", EXIT_FAILURE);
	return (full_path);
}
