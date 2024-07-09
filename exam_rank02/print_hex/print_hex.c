#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	if(str[0] == '-')
		return (0);

	int i;
	int result = 0;


	i = 0;
	while(str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void print_hex(int n)
{
	char *set = "0123456789abcdef";
	int result;
	int i;

	i = 0;

	if(n >= 16)
	{
		print_hex(n / 16);
	}
	write(1, &set[n % 16], 1);
}

int main(int argc, char **argv)
{

	char *set = "0123456789abcdef";
	char *result;

	if(argc == 2)
		print_hex(ft_atoi(argv[1]));

	write(1, "\n", 1);
}
