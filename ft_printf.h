#ifndef FT_PRINTF_H
# define FT_PTRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FORMATS "cspdiuxX%"
# define DECIMAL "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *, ...);

#endif
