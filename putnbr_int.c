#include "include/ft_printf.h"
#include "include/libft.h"

size_t  cnt_digit(int n)
{
    size_t dgt;

    dgt = 0;
    if (n < 0)
    {
        dgt++;
        if (n == -2147483648)
            return (11);
        n *= -1;
    }
    while (n > 0)
    {
        dgt++;
        n /= 10;
    }
    return (dgt);
}

size_t	putnbr_int(int n, s_print *ist)
{
    if (ist->sign && n >= 0)
        write(1, "+", 1);
    if (!ist->sign && ist->sp && n >= 0)
        write(1, " ", 1);
    ft_putnbr_fd(n, 1);
    return (cnt_digit(n));
}