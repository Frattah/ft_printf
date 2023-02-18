#include "include/ft_printf.h"
#include "include/libft.h"

void    init_s_print(s_print *nw)
{
    nw->wdt = 0;
    nw->prc = 0;
    nw->zero = 0;
    nw->pnt = 0;
    nw->dash = 0;
    nw->ln = 0;
    nw->sign = 0;
    nw->is_zero = 0;
    nw->perc = 0;
    nw->sp = 0;
}