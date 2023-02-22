#include "include/ft_printf.h"
#include "libft/libft.h"

void    mng_flag(int flg, s_print *ist)
{
    if (flg == '+')
        ist->sign++;
    if (flg == ' ')
        ist->sp++;
    if (flg == '0')
        ist->zero++;
}