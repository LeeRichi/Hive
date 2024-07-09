#include <libc.h>

void put_nbr(int n)
{
	char set[10] = "0123456789";
	if(n > 9)
		put_nbr(n / 10);
	write(1, &set[n % 10], 1);
}

int main(int argc, char **argv)
{
	put_nbr(argc - 1);
	write(1, "\n", 1);
}
