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
            ft_putchr_fd("0123456789abcdef"[hx], 1);
        else
            ft_putchr_fd("0123456789ABCDEF"[hx], 1);
    }
}

int     cnt_digit_x(unsigned int hx)
{
    int ln;

    ln = 0;
    if (hx == 0)
        return (1);
    while(hx > 0)
    {
        ln++;
        hx /= 16;
    }
    return (ln);
}

int     puthex_int(unsigned int hx, int c, s_print *ist)
{
    if (ist->zero)
    {
        if (ist->zero > cnt_digit_x(hx))
            ist->zero -= cnt_digit_x(hx);
        else
            ist->zero = 0;
        for (int i = 0; i < ist->zero; i++)
            write(1, "0", 1);
    } 
    puthex(hx, c);
    return (ist->zero + cnt_digit_x(hx));
}