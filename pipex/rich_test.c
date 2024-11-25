#include <stdio.h>
#include "lib/libft/libft.h"

int main(void)
{
    char **res;

    res = ft_split("     ", ' ');
    printf("%p\n", *res);
    free(res);
}