#include <stdlib.h>
#include <stdio.h>

void fprime(int n)
{
	int pr;

	int fac = 2;

	while(n > 1)
	{
		if(n % fac == 0)
		{
			n = n / fac;
			printf("%d", fac);
			if(n > 1)
				printf("*");
			fac--;
		}
		fac++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
}
