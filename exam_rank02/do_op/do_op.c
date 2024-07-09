#include <stdio.h>
#include <stdlib.h>


void cal(int first, char op, int second)
{
	if(op == '+')
		printf("%d", first + second);
	else if(op == '-')
		printf("%d", first - second);
	else if(op == '*')
		printf("%d", first * second);
	else if(op == '/')
		printf("%d", first / second);
	else if(op == '%')
		printf("%d", first % second);
	printf("\n");
}

int main(int ac, char **av)
{
	if(ac == 4)
	{
		cal(atoi(av[1]), av[2][0], atoi(av[3]));
	}
	else
		printf("\n");
}
