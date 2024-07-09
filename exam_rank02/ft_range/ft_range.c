#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int *arr;
	int i;

	if(start == end)
	{
		arr = malloc(sizeof(int));
		if(!arr)
			return (0);
		arr[0] = start;
		return (arr);
	}
	else if(end > start)
	{
		arr = malloc(sizeof(int) * (end - start + 1));
		if(!arr)
			return (0);
		i = 0;
		while(end >= start)
		{
			arr[i] = start;
			start++;
			i++;
		}
		return (arr);
	}
	else if(end < start)
	{
		arr = malloc(sizeof(int) * (start - end + 1));
		if(!arr)
			return (0);
		i = 0;
		while(end <= start)
		{
			arr[i] = start;
			start--;
			i++;
		}
		return (arr);
	}
	return (arr);
}

// int main(void)
// {
// 	int *arr = ft_range(-3, -3);
// 	for(int i = 0; i < 4; i++)
// 		printf("%d\n", arr[i]);
// }
