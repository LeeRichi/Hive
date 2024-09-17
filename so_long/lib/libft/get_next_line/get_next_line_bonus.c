/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:42:58 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/17 17:06:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	new_content = substr(content, len, ft_strlen(content) - len);
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

	res = ft_strjoin(content, buf);
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
			return (ft_free(&content));
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
	static char	*content[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	content[fd] = read_content(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	line = check_line(content[fd]);
	if (!line)
		return (ft_free(&content[fd]));
	content[fd] = jump_to_next_line(content[fd]);
	return (line);
}
