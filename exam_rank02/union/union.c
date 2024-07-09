#include <unistd.h>
#include <stdio.h>

int isFirst(char *s1, char c, int i)
{
	int j = 0;

	while(*s1)
	{
		if(*s1 == c)
		{
			break ;
		}
		s1++;
		j++;
	}
	if(j < i)
		return (0);
	else
		return (1);
}

int is_instring(char *s, char c)
{
	while(*s)
	{
		if(*s == c)
			return (1);
		s++;
	}
	return (0);
}

void ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while(s1[i])
	{
		if(s1[i] && isFirst(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}

	while(s2[j])
	{
		if(!is_instring(s1, s2[j]) && isFirst(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}
