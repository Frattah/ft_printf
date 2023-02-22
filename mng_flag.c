#include "include/ft_printf.h"
#include "libft/libft.h"

void    mng_flag(const char **f, s_print *ist)
{
    if (**f == '+')
        ist->sign++;
    if (**f == ' ')
        ist->sp++;
    if (**f == '0')
        ist->zero = ft_atoi(*f);
    if (**f == '-')
        ist->dash = ft_atoi(*f + 1);
    if (ft_isdigit(**f) && **f != 0)
        ist->zero = ft_atoi(*f);
}