#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i])
			i++;

		while(i > 0) //3, 2, 1
		{
			write(1, &argv[1][i - 1], 1);
			i--;
		}
	}
	write(1, "\n", 1);
}
