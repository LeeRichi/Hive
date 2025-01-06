/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:57 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/05 22:24:56 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*jump_to_next_line(char *content)
{
	char	*new_content;
	size_t	len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	if (content[len] == '\0')
	{
		free(content);
		return (NULL);
	}
	new_content = substr(content, len, gnl_strlen(content) - len);
	free(content);
	return (new_content);
}

char	*check_line(char *content)
{
	char	*new_line;
	size_t	len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	new_line = substr(content, 0, len);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*free_or_join(char *content, char *buf)
{
	char	*res;

	res = gnl_strjoin(content, buf);
	if (!res)
	{
		free(buf);
		buf = NULL;
		content = NULL;
		return (NULL);
	}
	buf = NULL;
	return (res);
}

char	*read_content(int fd, char *content)
{
	char	*content_buf;
	ssize_t	bytes;

	bytes = 1;
	content_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content_buf)
		return (ft_free(&content));
	while ((content && !ft_strchar(content, '\n') && bytes > 0) || !content)
	{
		bytes = read(fd, content_buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(content_buf);
			return (ft_free(&content_buf));
		}
		if (bytes == 0)
			break ;
		content_buf[bytes] = '\0';
		content = free_or_join(content, content_buf);
		if (!content)
			return (NULL);
	}
	free(content_buf);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free (content);
		content = NULL;
		return (NULL);
	}
	content = read_content(fd, content);
	if (!content)
		return (NULL);
	line = check_line(content);
	if (!line)
		return (ft_free(&content));
	content = jump_to_next_line(content);
	return (line);
}
