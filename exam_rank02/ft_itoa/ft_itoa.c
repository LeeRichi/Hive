#include <libc.h>
#include <stdlib.h>

int count_digits(int n)
{
	int i = 0;

	while(n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i+1);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int word_size;
	int sign = 1;
	int i = 0;

	if(nbr == -2147483648)
		return ("-2147483748");

	if(nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	// printf("%d\n", nbr);
	if(sign < 0)
		result = malloc(sizeof(char) * (count_digits(nbr) + 2));
	else
		result = malloc(sizeof(char) * (count_digits(nbr) + 1));
	if(!result)
		return (0);
	if(sign < 0)
	{
		result[count_digits(nbr) + 1] = '\0';
		result[0] = '-';
		i = count_digits(nbr);
		while(i > 0)
		{
			result[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	else
	{
		result[count_digits(nbr)] = '\0';
		i = count_digits(nbr) - 1;
		while(i >= 0)
		{
			result[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	return (result);
}

// int main(void)
// {
// 	printf("result: %s\n", ft_itoa(-1034));
// 	printf("result: %s\n", ft_itoa(1034));
// 	printf("result: %s\n", ft_itoa(2147483647));
// 	printf("result: %s\n", ft_itoa(-2147483648));
// }
