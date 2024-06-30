#include <unistd.h>

void ft_mirror(char *str)
{
	int i = 0;
	char new_char;

	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'm')
		{
			new_char = 'n' + ('m' - str[i]);
			write(1, &new_char, 1);
		}
		else if (str[i] >= 'n' && str[i] <= 'z')
		{
			new_char = 'm' - (str[i] - 'n');
			write(1, &new_char, 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'M')
		{
			new_char = 'N' + ('M' - str[i]);
			write(1, &new_char, 1);
		}
		else if (str[i] >= 'N' && str[i] <= 'Z')
		{
			new_char = 'M' - (str[i] - 'N');
			write(1, &new_char, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}

}

int main(int argc, char **argv)
{
	if(argc == 2)
		ft_mirror(argv[1]);

	write(1, "\n", 1);
}
