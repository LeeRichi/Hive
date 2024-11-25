/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:11:39 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/25 21:02:04 by chlee2           ###   ########.fr       */
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

static char	*build_and_check_path(t_data *data, char *dir, char *cmd, int *status)
{
	char	*one_path;
	char	*full_path;

	//
	(void)data;

	one_path = ft_strjoin(dir, "/");
	if (!one_path)
		show_error(data, "Memory allocation failed", 1, NULL);
	full_path = ft_strjoin(one_path, cmd);
	if (!full_path)
	{
		free(one_path);
		show_error(data, "Memory allocation failed", 1, NULL);
	}
	
	free(one_path);
	if (access(full_path, F_OK | X_OK) != 0)
	{
		free(full_path);
		*status = -1;
		// show_error(data, "testing for permission deny.", EXIT_FAILURE, full_path);
		return (NULL);
	}
	*status = 1;
	return (full_path);
}

static char *rev_str(char *str)
{
	int count;
	int i;
	char *new_str;

  	count = ft_strlen(str);
	new_str = malloc(sizeof(char) * (count + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (count != 0)
	{
		new_str[i] = str[count - 1];
		i++;
		count--;
	}
	new_str[i] = '\0';
	return (new_str);
}

static void	handle_cmd_error(char *cmd, t_data *data)
{
	(void)data;

	char *rev_cmd;

	rev_cmd = rev_str(cmd);
	if (!rev_cmd)
		return;
		
	// //
	// if (rev_cmd == NULL)
	// {
	// 	free(rev_cmd);
	// 	show_error(data, "test for only gets /0", 127, cmd);
	// }

	//a directory
	if (rev_cmd[0] == '/')
	{
		free(rev_cmd);
		show_error(data, "No such file or directory", 127, cmd);
	}

	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
	{
		free(rev_cmd);
		show_error(data, "Permission denied", 126, cmd);
	}

	if (access(cmd, X_OK) == -1 && cmd[0] == '/')
	{
		free(rev_cmd);
		show_error(data, "No such file or directory", 127, cmd);
	}

	if (access(cmd, F_OK) == -1)
	{
		free(rev_cmd);
		show_error(data, "command not found", 127, cmd);
	}

	if (access(cmd, F_OK) != 0)
	{
		free(rev_cmd);	
		show_error(data, "No such file or directory", 127, cmd);
	}

	if (access(cmd, X_OK) == -1 && !ft_strchr(cmd, '/'))
	{
		free(rev_cmd);
		show_error(data, "comment not found", 1, cmd);
	}

	free(rev_cmd);
	// show_error(data, "Permission denied.", 1, cmd);
}

char	*find_path(t_data *data, char *cmd, char **envp)
{
	char **s_cmd;
	char	**all_path;
	char	*full_path;
	int		i;

	int status;

	status = 0;

	full_path = NULL;

	s_cmd = split_command(cmd, data);
	all_path = get_paths(envp, data);
	if (!all_path)
	{
		// ft_free_tab(s_cmd);
		show_error(data, "No such file or directory", 127, cmd);
	}
	i = -1;
	while (all_path[++i])
	{
		full_path = build_and_check_path(data, all_path[i], s_cmd[0], &status);
		// if (!full_path)
		// {
		// 	ft_free_tab(s_cmd);
		// 	ft_free_tab(all_path);
		// 	show_error(data, "command not found", 127, cmd);
		// }
		if (full_path)
			break;
	}
	ft_free_tab(all_path);
	ft_free_tab(s_cmd);
	if (status == -1)
		handle_cmd_error(cmd, data);
	// if (!full_path)
	// 	show_error(data, "command not found.", EXIT_FAILURE, cmd);
	return (full_path);
}
