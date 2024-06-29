#include <stdio.h>
#include <stdlib.h>

int is_delimited(char c)
{
	if(c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int count_words(char *str)
{
	int words = 0;
	while(*str)
	{
		if(is_delimited(*str))
			words++;
		str++;
	}

	return (words + 1);
}

char *malloc_words(char *str)
{
	int i;
	char *result;

	i = 0;
	while(str[i])
		i++;

	result = (char *)malloc(sizeof(char) * (i + 1));
	if(!result)
		return (0);

	i = 0;
	while(str[i] && !is_delimited(str[i]))
	{
		result[i] = str[i];
		i++;
	}

	result[i] = '\0';
	return(result);
}

char    **ft_split(char *str)
{
	char **result;
	int words;
	int i;

	words = count_words(str);


	//check later either +1 or not
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if(!result)
		return (0);

	i = 0;
	while(*str)
	{
		while(*str && is_delimited(*str))
			str++;
		if(*str && !is_delimited(*str))
		{
			result[i] = malloc_words(str);
			i++;
			while(*str && !is_delimited(*str))
				str++;
		}
	}
	result[i] = NULL;
	return(result);
}

// int main(void)
// {
// 	char **result;

// 	result = ft_split("test 1 second");

// 	int i = 0;
// 	while(i < 3)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// }
