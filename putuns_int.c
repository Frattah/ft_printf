#include "include/ft_printf.h"
#include "libft/libft.h"

void    putuns(unsigned int un)
{
	if (un < 10)
		putchr_int("0123456789"[un]);
	else
	{
		putuns(un / 10);
		putuns(un % 10);
	}
}

size_t  putuns_int(unsigned int un)
{
    size_t ln;

    putuns(un);
    ln = 0;
    if (un == 0)
        return (1);
    while (un > 0)
    {
        ln++;
        un /= 10;
    }
    return (ln);
}