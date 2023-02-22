#include "include/ft_printf.h"
#include "libft/libft.h"

size_t  putchr_int(int c, s_print *ist)
{
    if (ist->zero)
        for (int i = 0; i < ist->zero - 1; i++)
            write(1, " ", 1);
    write(1, &c, 1);
    if (ist->dash)
        for (int i = 0; i < ist->dash - 1; i++)
            write(1, " ", 1);
    return (ist->dash + ist->zero);
}