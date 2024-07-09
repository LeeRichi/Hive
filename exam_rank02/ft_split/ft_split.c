// #include <stdio.h>
// #include <stdlib.h>

// int is_sep(char c)
// {
// 	return (c == ' ' || c == '\t' || c == '\n');
// }

// int count_word(char *str)
// {
// 	int i;
// 	int count = 0;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if(is_sep(str[i]))
// 			count++;
// 		i++;
// 	}
// 	return (count + 1);
// }

// char *malloc_word(char *str)
// {
// 	char *result;
// 	int i;

// 	i = 0;
// 	while(str[i])
// 		i++;

// 	result = malloc(i + 1);
// 	if(!result)
// 		return (0);

// 	i = 0;
// 	while(str[i] && !is_sep(str[i]))
// 	{
// 		result[i] = str[i];
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

// char    **ft_split(char *str)
// {
// 	char **result;
// 	int i;
// 	int j;

// 	int words;

// 	words = count_word(str);

// 	result = malloc(sizeof(char *) * words);
// 	if(!result)
// 		return (0);

// 	i = 0;
// 	while(*str)
// 	{
// 		while(*str && is_sep(*str))
// 			str++;
// 		if(*str && !is_sep(*str))
// 		{
// 			result[i] = malloc_word(str);
// 			i++;
// 			while(*str && !is_sep(*str))
// 				str++;
// 		}
// 		result[i] = NULL;
// 	}
// 	return (result);
// }


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

#include <stdlib.h>
#include <stdio.h>


int is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_word(char *str)
{
	int i;
	int count = 0;

	i = 0;
	while(str[i])
	{
		if(is_sep(str[i]))
		{
			count++;
			while(is_sep(str[i]))
				i++;
		}
		i++;
	}
	return (count + 1);
}

char *malloc_word(char *str)
{
	int i;
	char *result;

	i = 0;
	while(str[i])
		i++;

	result = malloc(i + 1);
	if(!result)
		return (0);

	i = 0;
	while(str[i] && !is_sep(str[i]))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';

	return (result);
}

char    **ft_split(char *str)
{
	char **result;
	int i;

	result = malloc(sizeof(char *) * count_word(str));
	if(!result)
		return (0);

	i = 0;
	while(*str)
	{
		while(*str && is_sep(*str))
			str++;

		if(*str && !is_sep(*str))
		{
			result[i] = malloc_word(str);
			i++;

			while(*str && !is_sep(*str))
				str++;
		}
		result[i] = NULL;
	}


	return (result);
}

int main(void)
{
	char **result;

	result = ft_split("test 1 second");

	int i = 0;
	while(i < 3)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
