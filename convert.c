#include "include/ft_printf.h"
#include "libft/libft.h"

size_t  convert(const char **f, s_print *ist)
{
    size_t ln;

    ln = 0;
    (*f)++;
    while (is_flag(**f))
    {
        mng_flag(**f, ist);
        (*f)++;
    }
    if (**f == 'd' || **f == 'i')
        ln = putnbr_int(va_arg(ist->args, int), ist);
    if (**f == 'c')
        ln = putchr_int(va_arg(ist->args, int));
    if (**f == 's')
        ln = putstr_int(va_arg(ist->args, char *));
    if (**f == '%')
        ln = putchr_int('%');
    if (**f == 'p')
        ln = putptr_int(va_arg(ist->args, unsigned long long));
    if (**f == 'x' || **f == 'X')
        ln = puthex_int(va_arg(ist->args, unsigned long long), **f);
    if (**f == 'u')
        ln = putuns_int(va_arg(ist->args, unsigned long long));
    return (ln);
}