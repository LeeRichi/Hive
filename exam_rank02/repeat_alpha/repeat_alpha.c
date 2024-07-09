#include <unistd.h>

void repeat_alpha(char *str)
{
	int count = 0;
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			count = str[i] - 'a';
			while(count >= 0)
			{
				write(1, &str[i], 1);
				count--;
			}
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			count = str[i] - 'A';
			while(count >= 0)
			{
				write(1, &str[i], 1);
				count--;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}


}
int main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);

	write(1, "\n", 1);
}
