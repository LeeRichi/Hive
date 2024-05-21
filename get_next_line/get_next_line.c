#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>

static size_t ft_count_len(char *a, char *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (a[i])
		i++;
	j = 0;
	while (b[j])
		j++;
	return (i + j);
}

static char *ft_strjoin(char *a, char *b)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	len;

    if (!a)
    {
        a = malloc(sizeof(char));
        if (!a)
            return (NULL);
        a[0] = 0;
    }
	len = ft_count_len(a, b);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (a[++i])
		new_str[i] = a[i];
	j = -1;
	while (b[++j])
		new_str[i + j] = b[j];
	new_str[i + j] = 0;
    //free(a); //necessary?
	return (new_str);
}

//mother function
// char	*get_next_line(int fd)
// {
// 	static char		*content;
// 	char			*content_buf;
// 	char			*line;
// 	ssize_t			bytes_read;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	content_buf = malloc(BUFFER_SIZE * sizeof(char));
// 	if (!content_buf)
// 		return (NULL);
// 	bytes_read = read(fd, content_buf, BUFFER_SIZE);
// 	if (bytes_read < 0)
// 	{
// 		free(content_buf);
//         return NULL;
// 	}
// 	while (bytes_read > 0)
// 	{
// 		content_buf[bytes_read] = '\0';
// 		line = ft_strjoin(content_buf, content);

// 		free(content);
// 		free(content_buf);
// 		printf("line: %s\n", line);
// 	}

// 	return (line);
// }

char *get_next_line(int fd)
{
    static char *content;
    char        *content_buf;
    char        *line;
    ssize_t     bytes_read;

    bytes_read = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    content_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!content_buf)
        return NULL;

    while ((content && bytes_read > 0 && !ft_strchar(content, '\n')) || !content)
    {
        bytes_read = read(fd, content_buf, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        content_buf[bytes_read] = '\0';
        content = ft_strjoin(content, content_buf);
        if (bytes_read <= 0)
        {
            free(content_buf);
            return NULL;
        }
        free(content_buf);
        if ()
        {
            
        }
    }
}


//test main
int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);

    char *line;

	line = get_next_line(fd1);

	printf("%s\n", line);
    while (line != NULL)
    	free(line);

    close(fd1);
    
    return (0);
}