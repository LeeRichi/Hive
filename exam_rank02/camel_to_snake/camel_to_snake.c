#include <libc.h>

int main(int argc, char **argv)
{
	int i = 0;
	char new_char;
	if(argc == 2)
	{
		while(argv[1][i])
		{
			while(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				write(1, "_", 1);
				new_char = argv[1][i] + 32;
				write(1, &new_char, 1);
				i++;
			}

			write(1, &argv[1][i], 1);
			i++;
		}
	}

	write(1, "\n", 1);
}
