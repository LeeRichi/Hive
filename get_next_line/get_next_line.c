/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:57 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/27 11:27:25 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *free_or_join(char *content, char *buf);

char *jump_to_next_line(char *content)
{
    char    *new_content;
    size_t  len;

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

char *check_line(char *content)
{
    char    *new_line;
    size_t  len;
    
    //printf("content in check_line: %s\n", content);
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

char    *read_content(int fd, char *content)
{
    char        *content_buf;
    ssize_t     bytes_read;

    bytes_read = 1;
    content_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!content_buf)
		return (ft_free(&content));
    // content = "";
    while ((content && !ft_strchar(content, '\n') && bytes_read > 0) || !content)
    {
        bytes_read = read(fd, content_buf, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(content_buf);
            return (ft_free(&content_buf));
        }
        if (bytes_read == 0)
            break;
        content_buf[bytes_read] = '\0';
        content = free_or_join(content, content_buf);
        if (!content)
            return (NULL);
    }
    free(content_buf);
    // if (ft_strlen(content) >= 0)
    //     return (content);
    // return (NULL);
    return (content);
}

char    *free_or_join(char *content, char *buf)
{
    char    *res;

    res = ft_strjoin(content, buf);
    if (!res)
    {
        free(buf);
        buf = NULL;
        //free(content);
        content = NULL;
        return (NULL);
    }
    buf = NULL;
    return(res);
}

char *get_next_line(int fd)
{
    static char *content;
    char        *line;
    
    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
    {
        free (content);
        content = NULL;
		return (NULL);
    }   
    content = read_content(fd, content);
    if (!content)
		return (ft_free(&content));
    line = check_line(content);
    if (!line)
		return (ft_free(&content));
    content = jump_to_next_line(content);
    return (line);
}

//test main
// int main(void)
// {
//     int fd1 = open("file.txt", O_RDONLY);

//     char *line;
//     int i;

//     i = 0;
//     while (i < 20)
//     {
//         line = get_next_line(fd1);
//         if (line)
//         {
//             printf("%s", line);
//             free(line);  // Free the line after use
//         }
//         else
//             break; // Exit loop if no more lines are read
//         i++;
//     }

//     close(fd1);
    
//     return (0);
// }
