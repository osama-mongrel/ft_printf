#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, c, 

int	print_format(char format, va_list ap)
{
	int	count;

	if (format == 'c')
		count = print_char(va_arg(ap, int));
	else if (format == 's')
		count = print_string(va_arg(ap, char *));
	else if (format == 'p')
		count = print_pointer(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		count = print_int(va_arg(ap, int));
	else if (format == 'u')
		count = print_nbr_base(va_arg(ap, int), DECIMAL);
	else if (format == 'x')
		count = print_nbr_base(va_arg(ap, int), HEX_LOW);
	else if (format == 'X')
		count = print_nbr_base(va_arg(ap, int), HEX_UP);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, *format, 1);
			continue ;
		}
		if (!ft_strchr(FORMATS, *++format))
		{
			count += write(1, format - 1, 2);
			continue ;
		}
		count += print_format(*format, ap);
	}
	va_end(ap);
	return (count);
}
