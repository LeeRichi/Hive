#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t result;

	int i;
	int j;

	i = 0;
	result = 0;
	while(s[i])
	{
		j = 0;
		while(reject[j])
		{
			if(s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}


// int main(void)
// {
// 	printf("%lu\n", strcspn("abc", "b"));
// 	printf("%lu\n", ft_strcspn("abc", "b"));
// }
