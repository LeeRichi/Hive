#include <unistd.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *result;

	int i = 0;
	while(src[i])
		i++;

	result = malloc(i + 1);
	if(!result)
		return (0);

	i = 0;
	while(src[i])
	{
		result[i] = src[i];
		i++;
	}

	result[i] = '\0';

	return (result);
}
