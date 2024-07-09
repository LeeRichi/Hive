#include <stdlib.h>
#include <stdio.h>

void pgcd(int first, int second)
{
	int denominator = 1;
	int result;

	while((denominator < first) || (denominator < second))
	{
		if((first % denominator == 0) && (second % denominator == 0))
		{
			result = denominator;
		}
		denominator++;
	}
	printf("%d", result);
}

int main(int argc, char **argv)
{
	if(argc == 3)
		pgcd(atoi(argv[1]),atoi(argv[2]));
	printf("\n");
}
