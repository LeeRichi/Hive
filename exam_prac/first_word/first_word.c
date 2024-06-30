#include <unistd.h>

int is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		while(is_delimiter(argv[1][i]))
			i++;
		while(argv[1][i] && !is_delimiter(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
