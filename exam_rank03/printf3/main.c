#include <unistd.h>
#include <stdarg.h>

int print_helper(va_list args, const char *str)
{
    int total = 0;
    int i = 0;

    while(str[i])
    {
        if (str[i] != '%')
        {
            total += write(1, str[i], 1);
        }
        else
        {
            i++;
            if (str[i] == 's')
                total += ft_putstr(va_arg(args, const char *));
            if (str[i] == 'd')

            if (str[i] == 'x')

        }
        i++;
    }
}

int ft_printf(const char *str, ...)
{
    int total;
    va_list args;

    va_start(args, str);
    total = print_helper(args, str);
    va_end(args);
    return (total);
}

int main(void)
{


}
