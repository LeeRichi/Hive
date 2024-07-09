#include <unistd.h>
#include <libc.h>

int count_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

void hidenp(char *first, char *second)
{
	int i = 0;
	int j = 0;

	int count = 0;
	int len = count_len(first);

	while(first[i])
	{
		while(second[j])
		{
			if(first[i] == second[j])
			{
				count++;
				break;
			}
			j++;
		}
		i++;
	}
	if(count == len)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		hidenp(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}
