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

	len = ft_count_len(a, b);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (a[i])
	{
		new_str[i] = a[i];
		i++;
	}
	j = 0;
	while (b[j])
	{
		new_str[i + j] = b[j];
		j++;
	}
	new_str[i + j] = 0;
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
    static char *content = NULL;
    char *content_buf;
    char *line = NULL;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    content_buf = malloc((BUFFER_SIZE + 1) * sizeof(char)); // Allocate space for BUFFER_SIZE + 1 for null terminator
    if (!content_buf)
        return NULL;

    bytes_read = read(fd, content_buf, BUFFER_SIZE);
    if (bytes_read < 0)
    {
        free(content_buf);
        return NULL;
    }

    if (bytes_read == 0) // No more content to read
    {
        free(content_buf);
        return NULL;
    }

    content_buf[bytes_read] = '\0'; // Null-terminate the content buffer

    if (content)
    {
        char *temp = ft_strjoin(content, content_buf); // Concatenate content_buf with existing content
        free(content);
        content = temp;
    }
    else
    {
        content = strdup(content_buf); // If content is NULL, set it to content_buf
    }

    free(content_buf); // Free content_buf after concatenation

    // Find the position of newline character in content, if any
    char *newline_pos = strchr(content, '\n');
    if (newline_pos != NULL)
    {
        *newline_pos = '\0'; // Replace newline character with null terminator
        line = strdup(content); // Allocate memory for line and copy content until newline
        memmove(content, newline_pos + 1, strlen(newline_pos + 1) + 1); // Move the remaining content after newline
    }
    else
    {
        line = strdup(content); // If no newline found, line is the entire content
        free(content);
        content = NULL;
    }

    return line;
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