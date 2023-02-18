#include "include/ft_printf.h"
#include "include/libft.h"

int ft_printf(const char *format, ...)
{
    s_print *ist = (s_print *)malloc(sizeof(s_print));
    va_start(ist->args, format);
    if (!ist)
        return (-1);
    init_s_print(ist);
    cnt_return(format, ist);
    va_end(ist->args);
    return(ist->ln);
}