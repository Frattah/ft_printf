#include "include/ft_printf.h"
#include "include/libft.h"

void    puthex(unsigned long long hx)
{
    if (hx >= 16)
    {
        puthex(hx / 16);
        puthex(hx % 16);
    }
    else
        putchr_int("0123456789abcdef"[hx]);
}

size_t  puthex_int(unsigned long long hx)
{
    size_t ln;

    ln = 0;
    puthex(hx);
    while(hx > 0)
    {
        ln++;
        hx /= 16;
    }
    return (ln);
}