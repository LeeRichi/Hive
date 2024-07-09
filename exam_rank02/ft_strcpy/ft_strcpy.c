#include <libc.h>

char    *ft_strcpy(char *s1, char *s2)
{
	char *og_point;
	og_point = s1;

	while(*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (og_point);
}

// int main(void)
// {
// 	char s1[10];
// 	char *s2 = "hello";

// 	printf("return: %s\n", ft_strcpy(s1, s2));

// 	printf("%s\n", s1);
// }
