#include <stdio.h>

/* ************************************************************************** */
/*                                isalpha                                     */
/* ************************************************************************** */

int main(void)
{
	printf("%d\n", ft_isalpha('A'));
}

/* ************************************************************************** */
/*                                isdigit                                     */
/* ************************************************************************** */

int main(void)
{
	printf("%d\n", isdigit('9'));
	printf("%d\n", ft_isdigit('9'));
}

/* ************************************************************************** */
/*                                isalnum                                     */
/* ************************************************************************** */

int main(void)
{
	printf("%d\n", isalnum('5'));
	printf("%d\n", ft_isalnum('5'));
}

/* ************************************************************************** */
/*                                isascii                                     */
/* ************************************************************************** */

int main(void)
{
	printf("%d\n", isascii(0));

	printf("%d\n", ft_isascii(0));
}

/* ************************************************************************** */
/*                                isprint                                     */
/* ************************************************************************** */

int main(void)
{
	printf("%d\n", ft_isprint(0));
	printf("%d\n", isprint(0));
}

/* ************************************************************************** */
/*                                strlen                                      */
/* ************************************************************************** */

int	main(void)
{
	// printf("%zu\n", ft_strlen("abc"));
	printf("%zu\n", strlen("abc"));
}

/* ************************************************************************** */
/*                                memset                                      */
/* ************************************************************************** */

int main(void)
{
	char str[10] = "abcefg";

	//memset(str, 'z', 2);
	ft_memset(str, 'z', 2); //zzbc

	printf("%s\n", str);
}

/* ************************************************************************** */
/*                                bzero                                       */
/* ************************************************************************** */

int main(void)
{
    char str[10] = "abc";

    ft_bzero(str, 1 * sizeof(char));
//	bzero(str, 1 * sizeof(char));

    printf("%s\n", str);
    return 0;
}


/* ************************************************************************** */
/*                                memcpy                                      */
/* ************************************************************************** */

/*int main(void)
{
    char str[10] = "abc";
	char src[5] = "xy";
//	memcpy(str, src, 1 * sizeof(char));
    //ft_memcpy(str, src, 3 * sizeof(char));
	
	ft_memcpy(((void *)0), ((void *)0), 3);
	//memcpy(((void *)0), ((void *)0), 3);
	
    printf("%s\n", str);
}*/

/* ************************************************************************** */
/*                                memmove                                     */
/* ************************************************************************** */

int main(void)
{
    unsigned char str[15] = "123456";
	unsigned char src[20] = "abcdefghijk";
	memmove(str, src, 15 * sizeof(unsigned char));
//    ft_memmove(str, src, 5 * sizeof(unsigned char));

    printf("%s\n", str);
}

/* ************************************************************************** */
/*                                strlcpy                                     */
/* ************************************************************************** */

int main(void)
{
	char dst[30] = "abcefg";
	char src[5] = "xxxxx"; //xx
	
	//strlcpy(dst, src, 3);
	//ft_strlcpy(dst, src, 3);
	
//	ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("%lu\n", ft_strlcpy(dst, "lorem ipsum dolor sit amet", 0));
	
//	printf("%d\n", str_len("123"));
	printf("%s\n", dst);
//	printf("%d\n", strlcpy());
}

/* ************************************************************************** */
/*                                strlcat                                     */
/* ************************************************************************** */

int main(void)
{
//	char dst[10] = "abcefg";
//	char src[5] = "xxxx";
//
//	printf("%zu\n", strlcat(dst, src, 10));
//
////	printf("%zu\n", ft_strlcat(dst, src, 10));
//	printf("%s\n", dst);
	char *dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
 	memset(dest, 'r', 15);

	printf("%zu\n", (ft_strlcat(dest, "lorem ipsum dolor sit amet", 5)));
	
	printf("%s\n", dest);
}

/* ************************************************************************** */
/*                                toupper                                     */
/* ************************************************************************** */

/*int main(void)
{    
    printf("%c\n", toupper('c'));

    printf("%c\n", ft_toupper('c'));
}*/

/* ************************************************************************** */
/*                                tolower                                     */
/* ************************************************************************** */

/*int main(void)
{
    printf("%c\n", tolower('C'));

    printf("%c\n", ft_tolower('A'));
}*/

/* ************************************************************************** */
/*                                strchr                                      */
/* ************************************************************************** */

/*int main(void)
{
	char dst[10] = "abcd";

	char *p;
	
	p = ft_strchr(dst, 'c');

	printf("%s\n", p);
}*/

/* ************************************************************************** */
/*                                strrchr                                     */
/* ************************************************************************** */

/*int main(void)
{
	char dst[10] = "abcdfdcdd";

	char *p;

	p = strrchr(dst, 'c');
//	p = ft_strrchr(dst, 'c'); //cdd

	printf("%s\n", p);
}*/

/* ************************************************************************** */
/*                                strncmp                                     */
/* ************************************************************************** */

/*int main(void)
{
//	char *first = "atoms\0\0\0\0";
//	char *second = "atoms\0bc";
	
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
}*/

/* ************************************************************************** */
/*                                memchr                                     */
/* ************************************************************************** */
/* 
int main(void)
{
	char *first = "abcefg";
	char *result;
	
	//result = ft_memchr(first, 'e', 5); //efg
	result = memchr(first, 'e', 5); //efg

	
	printf("%s\n", result);
//	printf("%d\n", ft_memchr(first, second, 2));
} */

/* ************************************************************************** */
/*                                memcmp                                     */
/* ************************************************************************** */

/*int main(void)
{
//	char first[] = {'a', 'b', 'c'};
//	char second[] = {'z', 'b', 'c'};
	char first[0] = "";
	char second[0] = "";
//	char third[0] = "";
//	char forth[0] = "";
	int result;
	
	
	result = ft_memcmp(first, second, 6);
//	result = memcmp(first, second, 5);
	
	printf("%d\n", result);
//	printf("%d\n", ft_memchr(first, second, 2));
}*/

/* ************************************************************************** */
/*                                strnstr                                     */
/* ************************************************************************** */

/*int main(void)
{
//	const char *largestring = "Foo Bar Baz";
//	const char *smallstring = "Bar";
	char * empty = (char*)"";
	char *result;
//
//	result = ft_strnstr(largestring, smallstring, 10);
//	result = strnstr(largestring, smallstring, 10);
	
	//printf("%s\n", result);
//	printf("%d\n", ft_memchr(first, second, 2));
 
	result = ft_strnstr(empty, "", 0);
	//result = strnstr(empty, "", 0);

	printf("%s\n", result);
}*/

/* ************************************************************************** */
/*                                atoi                                        */
/* ************************************************************************** */

/* int main(void)
{
	printf("My: %d\n", ft_atoi("-21474836481111111111"));

	printf("OG: %d\n", atoi("-21474836481111111111"));

	printf("Long Max: %ld\n", LONG_MAX);

	printf("My: %d\n", ft_atoi("-9223372036854775809"));

	printf("OG: %d\n", atoi("-9223372036854775809"));

	printf("INT_MIN: %d\n", INT_MIN);	

	// check(ft_atoi((e + to_string(INT_MIN)).c_str()) == INT_MIN); showLeaks();

	// printf("My atoi: %d\n", ft_atoi("9223372036854775810"));
	// printf("OG atoi: %d\n", atoi("9223372036854775810"));


	// printf("OG atoi: %d\n", atoi("9223372036854775806"));
	// printf("OG atoi: %d\n", atoi("9223372036854775805"));
	
	// printf("--out of range from here---\n");
	
	// printf("My atoi: %d\n", ft_atoi("2147483648"));
	// printf("My atoi: %d\n", ft_atoi("-9223372036854775809"));
	
	// printf("OG atoi: %d\n", atoi("2147483648"));
	// printf("OG atoi: %d\n", atoi("-9223372036854775809"));
}
 */

/* ************************************************************************** */
/*                                calloc                                      */
/* ************************************************************************** */

/*int main(void)
{
	int *test_str;
	int i;
	
	test_str = (int *)calloc(25, SIZE_MAX);
	//test_str = (int *)ft_calloc(25, SIZE_MAX);
	
	i = 0;
	while (i < 25)
	{
		test_str[i] = i;
		i++;
	}

	i = 0;
	while (i < 25)
	{
		printf("%d\n", test_str[i]);
		i++;
	}
	
	free(test_str);
	
    return 0;
}*/

/* ************************************************************************** */
/*                                strdup                                      */
/* ************************************************************************** */

/*int main(void)
{
	const char	*test_str;
	const char	*return_str;

	test_str = "123";
	return_str = ft_strdup(test_str);

	printf("%s\n", return_str);

    free((void *)return_str);
}*/

/* ************************************************************************** */
/*                                ft_substr                                   */
/* ************************************************************************** */

/* int main(void)
{
	char *str;
	char *newStr;
	
	str = "this is a string.";
	
	// newStr = ft_substr("", 1, 1);

	newStr = ft_substr("abcd", 2, 2);

	// printf("%s\n", str);
	printf("New: %s\n", newStr);


	printf("Len: %zu\n", ft_strlen(""));

	free(newStr);
} 
*/

/* ************************************************************************** */
/*                                ft_strjoin                                  */
/* ************************************************************************** */

/*int main(void)
{
	//char *first_str;
	//char *second_str;
	//char *result;

	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;

	//first_str = "this is a string.";
	//second_str = "Se on toinen merkkijono.";

	strjoin = ft_strjoin(s1, s2);

	printf("%s\n", strjoin);

	free(strjoin);
}*/

/* ************************************************************************** */
/*                                ft_strtrim                                  */
/* ************************************************************************** */

/* int main(void)
{
	// char *str;
 	// char *sep;

 	// str = "     ";
 	// sep = " ";

 	//printf("%s\n", ft_strtrim(str, sep));

	printf("%s\n", ft_strtrim("", ""));
}
*/

/* ************************************************************************** */
/*                                ft_split                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                ft_itoa                                     */
/* ************************************************************************** */

/*int main(void)
{
	printf("My result: %s\n", ft_itoa(0)); //0
}*/

/* ************************************************************************** */
/*                                ft_strmapi                                  */
/* ************************************************************************** */

/*char	to_upper(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}*/

/*int main(void)
{
    const char *input = "Hello my friend";

    char *output = ft_strmapi(input, to_upper);

	printf("before: %s\n", input);
    printf("after: %s\n", output);

    free(output);

    return 0;
}*/

/* ************************************************************************** */
/*                                ft_striteri                                 */
/* ************************************************************************** */

/*void print_indexed_char(unsigned int index, char *c)
{
    printf("Character at index %u: %c\n", index, *c);
}

int main(void)
{
    char str[] = "Hello, world!";
    
    ft_striteri(str, print_indexed_char);
    
    return 0;
}*/

/* ************************************************************************** */
/*                                ft_putchar_fd                               */
/* ************************************************************************** */

/*int main(void)
{
    // Test 1: Write character 'A' to standard output (stdout)
    ft_putchar_fd('A', STDOUT_FILENO);

    // Test 2: Write character 'B' to standard error (stderr)
    ft_putchar_fd('B', STDERR_FILENO);

    return 0;
}*/

/* ************************************************************************** */
/*                                ft_putstr_fd                                */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_putendl_fd                               */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_putnbr_fd                                */
/* ************************************************************************** */

/*int main(void)
{
    int fd = 1;

    ft_putnbr_fd(123, fd);
    ft_putchar_fd('\n', fd);

    ft_putnbr_fd(-456, fd);
    ft_putchar_fd('\n', fd);

    ft_putnbr_fd(0, fd);
    ft_putchar_fd('\n', fd);
	
    ft_putnbr_fd(-2147483648, fd);
    ft_putchar_fd('\n', fd);

    ft_putnbr_fd(2147483647, fd);
    ft_putchar_fd('\n', fd);

    return (0);
}*/

/* ************************************************************************** */
/*                                ft_lstnew                                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstadd_front                             */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstadd_back                              */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstdelone                                */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstclear                                 */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstiter                                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                ft_lstmap                                   */
/* ************************************************************************** */
