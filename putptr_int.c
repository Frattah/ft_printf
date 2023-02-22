#include "include/ft_printf.h"
#include "libft/libft.h"

size_t  cnt_ptr_dgt(unsigned long long ptr)
{
    int ln;

    ln = 0;
    while (ptr > 0)
    {
        ln++;
        ptr /= 16;
    }
    return (ln);
}

void    putptr(unsigned long long ptr)
{
    if (ptr >= 16)
    {
        putptr(ptr / 16);
        putptr(ptr % 16);
    }
    else
        putchr_int("0123456789abcdef"[ptr]);
}

size_t  putptr_int(unsigned long long ptr)
{
    size_t ln;

    ln = 0;
    ln += write(1, "0x", 2);
    if (ptr == 0)
        ln += write(1, "0", 1);
    else
    {
        ln += cnt_ptr_dgt(ptr);
        putptr(ptr);
    }
    return (ln);
}