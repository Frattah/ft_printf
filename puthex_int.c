#include "include/ft_printf.h"
#include "libft/libft.h"

void    puthex(unsigned int hx, int c)
{
    if (hx >= 16)
    {
        puthex(hx / 16, c);
        puthex(hx % 16, c);
    }
    else
    {
        if (c == 'x')
            putchr_int("0123456789abcdef"[hx]);
        else
            putchr_int("0123456789ABCDEF"[hx]);
    }
}

size_t  puthex_int(unsigned int hx, int c)
{
    size_t ln;

    ln = 0;
    puthex(hx, c);
    if (hx == 0)
        return (1);
    while(hx > 0)
    {
        ln++;
        hx /= 16;
    }
    return (ln);
}