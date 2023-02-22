#include "include/ft_printf.h"
#include "libft/libft.h"

void    putuns(unsigned int un)
{
	if (un < 10)
		ft_putchr_fd("0123456789"[un], 1);
	else
	{
		putuns(un / 10);
		putuns(un % 10);
	}
}

int     cnt_digit_u(unsigned int un)
{
    int ln;

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

int  putuns_int(unsigned int un, s_print *ist)
{
    if (ist->zero)
    {
        if (ist->zero > cnt_digit_u(un))
            ist->zero -= cnt_digit_u(un);
        else
            ist->zero = 0;
        for (int i = 0; i < ist->zero; i++)
            write(1, "0", 1);
    } 
    putuns(un);
    return (ist->zero + cnt_digit_u(un));
}