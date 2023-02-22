#include "include/ft_printf.h"
#include "libft/libft.h"

void cnt_return(const char *format, s_print *ist)
{
    while (*format)
    {
        if (*format == '%')
            ist->ln += convert(&format, ist);
        else
            ist->ln += write(1, format, 1);
        format++;
    }
}