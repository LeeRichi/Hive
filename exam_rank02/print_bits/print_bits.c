#include <libc.h>

void    print_bits(unsigned char octet)
{
	char *set = "01";
	// char digit;

	int i = 7;

	while(i >= 0)
	{
		char digit = (octet >> i) & 1;
		write(1, &set[digit], 1);
		i--;
	}
}

// int main(void)
// {
// 	print_bits(2);
// }
