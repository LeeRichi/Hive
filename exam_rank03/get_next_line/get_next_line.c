#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char)c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}

size_t ft_strlen(const char *s)
{
	size_t len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

void ft_strcpy(char *s1, const char *s2)
{
	while(*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

char *ft_strdup(const char *s2)
{
	char *dst;

	dst = malloc(ft_strlen(s2) + 1);
	if(!dst)
		return (NULL);
	ft_strcpy(dst, s2);
	return (dst);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *join;
	if(!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!join)
		return (NULL);

	ft_strcpy(join, s1);
	ft_strcpy(join + ft_strlen(s1), s2);

	free(s1);

	return (join);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line;
	char *new_line;
	int countread;

	line = ft_strdup(buf);
	while (!(new_line = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if(ft_strlen(line) == 0)
	{
		return (free(line), NULL);
	}

	if(new_line)
	{
		ft_strcpy(buf, new_line + 1);
		*(new_line + 1) = '\0';
	}
	else
		buf[0] = '\0';

	return (line);
}

// int main(void)
// {
// 	// char *test = "test";

// 	// char *second = "second";

// 	// char *result;

// 	// result = ft_strjoin(test, second);

// 	// printf("result: %s\n", result);

// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);

// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }
