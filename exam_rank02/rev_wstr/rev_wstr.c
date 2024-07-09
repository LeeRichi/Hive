// #include <stdlib.h>
// #include <unistd.h>

// int is_delimiter(char c)
// {
// 	return (c == ' ' || c == '\t');
// }

// int ft_print_word(char *str, int index, int end_index)
// {
// 	int temp;
// 	temp = index;

// 	while(index < end_index)
// 	{
// 		write(1, &str[index], 1);
// 		index++;
// 	}
// 	end_index = temp;
// 	return (end_index);
// }

// void rev_wstr(char *str)
// {
// 	int i;
// 	int j;

// 	int end_index;
// 	while(str[i])
// 		i++;
// 	end_index = i;
// 	while(i >= -1)
// 	{
// 		if(is_delimiter(str[i]) || i == -1)
// 		{
// 			end_index = ft_print_word(str, i + 1, end_index) - 1;
// 			if(i != -1)
// 				write(1, " ", 1);
// 		}
// 		i--;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	if(argc == 2)
// 		rev_wstr(argv[1]);
// 	write(1, "\n", 1);
// }


#include <stdlib.h>
#include <unistd.h>

int is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

void ft_print_word(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

void rev_wstr(char *str)
{
	int i;
	int end;

	// Initialize i to the end of the string
	i = 0;
	while (str[i])
		i++;
	end = i;

	while (i >= 0)
	{
		if (is_delimiter(str[i]) || i == 0)
		{
			if (i == 0)
				ft_print_word(str, i, end);
			else
				ft_print_word(str, i + 1, end);
			if (i > 0)
				write(1, " ", 1);
			end = i;
		}
		i--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return 0;
}
