/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:57 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/22 16:39:45 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *content;
    char        *content_buf;
    char        *new_line;
    ssize_t     bytes_read;

    bytes_read = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    content_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!content_buf)
        return NULL;
    content = "";
    while ((content && bytes_read > 0 && !ft_strchar(content, '\n')) || !content) //no line break
    {
        bytes_read = read(fd, content_buf, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(content_buf);
            return NULL;
        }
        content_buf[bytes_read] = '\0';
        content = ft_strjoin(content, content_buf);
        free(content_buf);
        if (ft_strlen(content) > 0) //if there's something
        {
            // if (ft_check_line_break(content) > 0)
            // {
            //     return (ft_reverse_strchar(content, '\n'));
            // }
            // return (ft_strchar(content, '\n'));
            printf("This is content: %s\n", content);
            
            // return (ft_reverse_strchar(content, '\n'));
            printf("This is trim-content: %s\n", ft_reverse_strchar(content, '\n'));
        }
        return (NULL);
    }
}

//test main
int main(void)
{
    int fd1 = open("file2.txt", O_RDONLY);

    char *line;
    int i;

    i = 0;
    while (i < 10)
    {
        line = get_next_line(fd1);
        //printf("Each Line: %s\n", line);
        i++;
    }

	// printf("%s\n", line);
    // while (line != NULL)
    // 	free(line);

    close(fd1);
    
    return (0);
}