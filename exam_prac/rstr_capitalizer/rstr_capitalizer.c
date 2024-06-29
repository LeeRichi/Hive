#include <libc.h>

void rstr_capitalizer(char *s)
{
	char *og = s;
	int i = 0;

	//lowercase all of them
	while(*s)
	{
		if(*s >= 'A' && *s <= 'Z')
			*s = *s + 32;
		s++;
	}

	while(og[i])
	{
		if((og[i] == '\t' || og[i] == ' ') && (og[i - 1] >= 'a' && og[i - 1] <= 'z'))
			og[i - 1] = og[i - 1] - 32;
		while(og[i] == '\t' || og[i] == ' ')
			i++;
		i++;
	}
	if((og[i - 1] >= 'a' && og[i - 1] <= 'z'))
		og[i - 1] = og[i - 1] - 32;

	i = 0;
	while(og[i])
	{
		write(1, &og[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i = 1;

	// printf("%d\n", argc);

	if(argc >= 2)
	{
		while(i <= argc - 1)
		{
			rstr_capitalizer(argv[i]);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
