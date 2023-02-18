#include "include/ft_printf.h"
#include "include/libft.h"

void    mng_flag(int flg, s_print *ist)
{
    if (flg == '+')
        ist->sign++;
    if (flg == ' ')
        ist->sp++;
}