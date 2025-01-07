#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *s)
{
	int total = 0;
	int i = 0;

	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	if (s[i] == '\0')
	{
		return (total);
	}
	while (s[i] != '\0')
	{
		total += write(1, &s[i], 1);
		i++;
	}
	return (total);
}

int ft_putnbr(long nbr, int base)
{
	int total = 0;
	char *base_char = "0123456789abcdef";

	if (nbr < 0)
	{
		total = write(1, '-', 1);
		nbr = -nbr;
	}
	if (nbr < base)
	{
		total = write(1, &base_char[nbr], 1);
	}
	else
	{
		total += ft_putnbr(nbr / base, base);
		total += ft_putnbr(nbr % base, base);
	}
	return (total);
}

int printf_helper(va_list args, char *s)
{
	int total = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			total = write(1, &s[i], 1);
		}
		else
		{
			i++;
			if(s[i] == 's')
				total += ft_putstr(va_arg(args, const char*));
			else if(s[i] == 'd')
				total += ft_putnbr(va_arg(args, int), 10);
			else if(s[i] == 'x')
				total += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		i++;
	}
	return (total);
}

int ft_printf(char *s, ...)
{
	int total = 0;
	va_list args;
	va_start(args, s);
	total += printf_helper(args, s);
	va_end(args);
	return (total);
}
