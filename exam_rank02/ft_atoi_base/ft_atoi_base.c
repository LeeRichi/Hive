// #include <stdio.h>

// // int	ft_atoi_base(const char *str, int str_base)
// // {
// // 	int i;
// // 	int flag;
// // 	int result;

// // 	flag = 1;
// // 	i = 0;
// // 	result = 0;
// // 	while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
// // 		i++;
// // 	if(str[i] == '-' || str[i] == '+')
// // 	{
// // 		if(str[i] == '-')
// // 			flag *= -1;
// // 		i++;
// // 	}
// // 	while(str[i] >= '0' && str[i] <= '9')
// // 	{
// // 		result = result * 10 + (str[i] - '0');
// // 		i++;
// // 	}
// // 	return (result * flag);
// // }

// // int main(void)
// // {
// // 	printf("%d\n", ft_atoi_base("12345", 16));
// // }


// int convert_to(char n)
// {
// 	if(n >= '0' && n <= '9')
// 		return (n - '0');
// 	else if(n >= 'A' && n <= 'F')
// 		return (n - 'A' + 10);
// 	else if(n >= 'a' && n <= 'f')
// 		return (n - 'a' + 10);

// 	return (-1);
// }

// int	ft_atoi_base(const char *str, int str_base)
// {
// 	int value = 0;
// 	int flag = 1;
// 	int result = 0;

// 	if(str_base < 2 || str_base > 16)
// 		return (0);

// 	int i = 0;
// 	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;

// 	if(str[i] == '-' || str[i] == '+')
// 	{
// 		if(str[i] == '-')
// 			flag *= -1;
// 		i++;
// 	}

// 	while(str[i])
// 	{
// 		value = convert_to(str[i]);

// 		if (value < 0 || value >= str_base) {
//             break; // invalid character for the given base
//         }

// 		result = result * str_base + value;
// 		i++;
// 	}

// 	return (result * flag);
// }


// int main(void) {
//     printf("%d\n", ft_atoi_base("12345", 10)); // Should print 12345
//     printf("%d\n", ft_atoi_base("12345", 16)); // Should print 74565
//     printf("%d\n", ft_atoi_base("1A", 16));    // Should print 26
//     printf("%d\n", ft_atoi_base("Z", 36));     // Unsupported base, should print 0
//     printf("%d\n", ft_atoi_base("1011", 2));   // Should print 11
//     printf("%d\n", ft_atoi_base("12fdb3", 16)); // Should print 1224083
// }


#include <stdio.h>

int convert_digit(char c)
{
	int result;

	if(c >= '0' && c <= '9')
		return (c - '0');
	else if(c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if(c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int result = 0;
	int flag = 1;
	int value;

	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			flag *= -1;
		i++;
	}

	while(str[i])
	{
		value = convert_digit(str[i]);

		if(value < 0 || value >= str_base)
			break;

		result = result * str_base + value;
		i++;
	}
	return (result * flag);
}


// int main(void) {
//     printf("%d\n", ft_atoi_base("12345", 10)); // Should print 12345
//     printf("%d\n", ft_atoi_base("12345", 16)); // Should print 74565
//     printf("%d\n", ft_atoi_base("1A", 16));    // Should print 26
//     printf("%d\n", ft_atoi_base("Z", 36));     // Unsupported base, should print 0
//     printf("%d\n", ft_atoi_base("1011", 2));   // Should print 11
//     printf("%d\n", ft_atoi_base("12fdb3", 16)); // Should print 1224083
// }
