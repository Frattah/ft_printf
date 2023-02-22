#include "include/ft_printf.h"
#include "libft/libft.h"

size_t  putchr_int(int c)
{
    return (write(1, &c, 1));
}