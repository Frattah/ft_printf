#include "include/ft_printf.h"
#include "libft/libft.h"

int  cnt_digit_d(int n)
{
    int dgt;

    if (n == 0)
        return (1);
    dgt = 0;
    if (n < 0)
    {
        dgt++;
        if (n == -2147483648)
            return (11);
        n *= -1;
    }
    while (n > 0)
    {
        dgt++;
        n /= 10;
    }
    return (dgt);
}

void	putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		return ;
	}
	else if (n < 0)
		n *= -1;
	if (n < 10)
		ft_putchr_fd("0123456789"[n], 1);
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

size_t	putnbr_int(int n, s_print *ist)
{
    if (ist->sign && n >= 0 && ist->zero == 0)
        write(1, "+", 1);
    if (n < 0)
        ft_putstr_fd("-", 1);
    if (ist->zero)
    {
        if (ist->zero > cnt_digit_d(n))
            ist->zero -= cnt_digit_d(n);
        else
            ist->zero = 0;
        for (int i = 0; i < ist->zero; i++)
            write(1, "0", 1);
    }        
    if (!ist->sign && ist->sp && n >= 0)
        write(1, " ", 1);
    putnbr(n);
    return (ist->sign + cnt_digit_d(n) + ist->zero);
}