#include "get_next_line.h"

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
char	*get_next_line(int fd)
{
	static char		*content;
	char			*content_buf;
	char			*line;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content_buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!content_buf)
		return (NULL);
	bytes_read = read(fd, content_buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(content_buf);
        return NULL;
	}
	while (bytes_read > 0)
	{
		content_buf[bytes_read] = '\0';
		line = ft_strjoin(content_buf, content);

		free(content);
		free(content_buf);
		printf("line: %s\n", line);
	}

	return (line);
}

//chat-gpt test main
int main(void) {
    // For testing purposes, you can simulate input using an array of strings
    char *input[] = {
        "This is line 1.\n",
        "This is line 2.\n",
        "This is line 3.\n",
        "This is line 4.\n",
        "This is line 5.\n",
        NULL // Mark the end of input with a NULL pointer
    };

    // Simulate reading from a file descriptor (replace this with your actual file descriptor)
    int fd = 0; // Use stdin (0) for simplicity

    // Iterate over the input array and call get_next_line for each string
    for (int i = 0; input[i] != NULL; i++) {
        printf("Reading line %d:\n", i + 1);
        char *line = get_next_line(fd);
        if (line != NULL) {
            printf("Read line: %s\n", line);
            free(line); // Free allocated memory for the line
        } else {
            printf("Failed to read line\n");
        }
    }

    return 0;
}