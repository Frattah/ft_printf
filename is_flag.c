#include "include/ft_printf.h"
#include "include/libft.h"

int is_flag(int c)
{
    return (c == '#' || c == '+' || c == ' ' || ft_isdigit(c));
}