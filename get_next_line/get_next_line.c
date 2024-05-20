#include "get_next_line.h"

static size_t *ft_count_len(char *a, char *b)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

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

	new_str = malloc((ft_count_len(a, b) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (a[i])
		new_str[i] = a[i++];
	j = 0;
	while (b[j])
		new_str[i + j] = b[j++];
	new_str[i + j] = 0;
	return (new_str);
}

//mother function
// char	*get_next_line(int fd)
// {
// 	static *char	content;
// 	*char			content_buf;
// 	*char			line;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, content, BUFFER_SIZE) < 0);
// 		return (NULL);
// 	content_buf = malloc(BUFFER_SIZE * sizeof(char));
// 	if (!content_buf)
// 		return (NULL);
// 	ft_strjoin(content_buf, content);
// }

int main(void)
{
	printf("%s\n", ft_strjoin("abc", "efg"));
}
