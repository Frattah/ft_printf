#include "include/ft_printf.h"
#include "include/libft.h"

size_t	putstr_int(char *s)
{
	if (s != NULL)
		return (write(1, s, ft_strlen(s)));
    ft_putstr_fd("(null)",1);
    return (0);
}