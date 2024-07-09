#include <unistd.h>

int is_first(char *str, char c, int index)
{
	int i = 0;

	while(str[i])
	{
		if(str[i] == c)
		{
			if(i > index)
				return (0);
		}
		i++;
	}
	return (1);
}

void inter(char *first, char *second)
{
	int i;
	int j;

	i = 0;
	while(first[i])
	{
		j = 0;
		while(second[j])
		{
			if(first[i] == second[j] && is_first(first, second[j], i))
			{
				write(1, &first[i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	if(argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}
