#include "ft_printf.h"

int	print_char(int	c)
{
	return (write(1, &c, 1));
}

int	print_str(char	*s)
{
	int	len;

	if (!s)
		return (print_str("(null)"));
	len = ft_strlen(s);
	return (write(1, s, len));
}

int print_nbr(long n, char *base)
{
	int count;
	int	base_len;

	count = 0;
	base_len = (int)ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		return (count + 1 + print_nbr(-n, base));
	}
	if (n > base_len)
		count += print_nbr(n / base_len, base);
	return (count + print_char(base[n % base_len]));
}

int	print_format(char spec, va_list ap)
{
	int				count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_str(va_arg(ap, char *));
/*	else if (spec == 'p')
		count += print_ptr(va_arg(ap, void *));*/
	else if (spec == 'd' || spec == 'i')
		count += print_nbr(va_arg(ap, int), DECIMAL);
	else if (spec == 'u')
		count += print_nbr(va_arg(ap, unsigned int), DECIMAL);
	else if (spec == 'x')
		count += print_nbr(va_arg(ap, unsigned int), HEX_LOW);
	else if (spec == 'X')
		count += print_nbr(va_arg(ap, unsigned int), HEX_UP);
	else if (spec == '%')
		count += print_char('%');
	else
		count += (print_char('%') + print_char(spec));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			count += print_format(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
