#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char c;
	ft_printf("%", ft_printf("%p\n", &c));
	printf("%", printf("%p\n", &c));
}
