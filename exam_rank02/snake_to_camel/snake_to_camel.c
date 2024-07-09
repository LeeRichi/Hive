#include <unistd.h>

void snake_to_camel(char *str)
{
	int i;

	char c;

	i = 0;
	while(str[i])
	{
		c = str[i];
		if(str[i] == '_')
		{
			i++;
			c = str[i] - 32;
		}
		write(1, &c, 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		snake_to_camel(argv[1]);
	}

	write(1, "\n", 1);
}
