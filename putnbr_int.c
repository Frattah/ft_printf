/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:14:40 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/24 10:39:29 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int	cnt_digit_d(int n)
{
	int	dgt;

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

void	zero_d(int n, t_print *ist)
{
	int	i;

	i = -1;
	if (ist->zero)
	{
		if (ist->zero > cnt_digit_d(n))
			ist->zero -= cnt_digit_d(n);
		else
			ist->zero = 0;
		while (++i < ist->zero)
			write(1, "0", 1);
	}
	if (ist->prc)
	{
		i = -1;
		while (++i < ist->prc - cnt_digit_d(n) + (n < 0))
			write(1, "0", 1);
	}
	putnbr(n);
}

size_t	putnbr_int(int n, t_print *ist)
{
	int	i;
	int	cnd_tmp;

	i = -1;
	if (ist->sign && n >= 0 && ist->zero == 0)
		write(1, "+", 1);
	if (ist->sp && n >= 0 && ist->zero == 0)
		write(1, " ", 1);
	if (n < 0)
		ft_putstr_fd("-", 1);
	if (ist->dash)
	{
		putnbr(n);
		while (++i < ist->dash - cnt_digit_d(n))
			write(1, " ", 1);
		if (ist->dash > cnt_digit_d(n))
			return (ist->dash);
		return (cnt_digit_d(n));
	}
	zero_d(n, ist);
	if (ist->prc > cnt_digit_d(n) - (n < 0))
		return (ist->sign + ist->prc + ist->zero + (n < 0));
	cnd_tmp = ((ist->sign && n >= 0) + (ist->sp && n >= 0));
	return (cnd_tmp + cnt_digit_d(n) + ist->zero);
}
