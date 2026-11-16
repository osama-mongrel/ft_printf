#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define FORMATS "cspdiuxX%"
# define DECIMAL "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *, ...);
int	printf_format(char, va_list);
int	print_nbr(long, char *);
int	print_str(char *);
int	print_char(int c);
int	print_ptr(unsigned long);

#endif
