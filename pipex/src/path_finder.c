/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:11:39 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 16:32:27 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**split_command(char *cmd, t_data *data)
{
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		show_error(data, "s_cmd split malloc failed.", EXIT_FAILURE, NULL);
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
				show_error(data, "all_path split failed.", EXIT_FAILURE, NULL);
			return (all_path);
		}
		i++;
	}
	return (NULL);
}

static char	*build_and_check_path(t_data *data, char *dir, char *cmd, int *sig)
{
	char	*one_path;
	char	*full_path;

	one_path = ft_strjoin(dir, "/");
	if (!one_path)
		show_error(data, "Memory allocation failed", 1, NULL);
	full_path = ft_strjoin(one_path, cmd);
	free(one_path);
	if (!full_path || access(full_path, F_OK | X_OK) != 0)
	{
		free(full_path);
		*sig = -1;
		return (NULL);
	}
	*sig = 1;
	return (full_path);
}

static void	handle_cmd_error(char *cmd, t_data *data, char **arguments)
{
	char	*rev_cmd;

	rev_cmd = rev_str(cmd);
	if (!rev_cmd)
		return ;
	if (rev_cmd[0] == '/' || access(cmd, F_OK) == -1)
	{
		free(rev_cmd);
		ft_free_tab(arguments);
		show_error(data, "No such file or directory", 127, cmd);
	}
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
	{
		free(rev_cmd);
		ft_free_tab(arguments);
		show_error(data, "Permission denied", 126, cmd);
	}
	free(rev_cmd);
	ft_free_tab(arguments);
}

char	*find_path(t_data *data, char *cmd, char **envp, char **arguments)
{
	char	**s_cmd;
	char	**all_path;
	char	*full_path;
	int		status;
	int		i;

	full_path = NULL;
	s_cmd = split_command(cmd, data);
	all_path = get_paths(envp, data);
	if (!all_path)
		show_error(data, "No such file or directory", 127, cmd);
	status = 0;
	i = -1;
	while (all_path[++i] && !full_path)
		full_path = build_and_check_path(data, all_path[i], s_cmd[0], &status);
	ft_free_tab(all_path);
	ft_free_tab(s_cmd);
	if (!full_path)
	{
		ft_free_tab(arguments);
		show_error(data, "command not found.", 127, cmd);
	}
	if (status == -1)
		handle_cmd_error(cmd, data, arguments);
	return (full_path);
}
