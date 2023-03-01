/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:37:51 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:54 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

void	puthex(unsigned int hx, int c)
{
	if (hx >= 16)
	{
		puthex(hx / 16, c);
		puthex(hx % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchr_fd("0123456789abcdef"[hx], 1);
		else
			ft_putchr_fd("0123456789ABCDEF"[hx], 1);
	}
}

int	cnt_digit_x(unsigned int hx)
{
	int	ln;

	ln = 0;
	if (hx == 0)
		return (1);
	while (hx > 0)
	{
		ln++;
		hx /= 16;
	}
	return (ln);
}

void	zero_x(unsigned int hx, t_print *ist)
{
	int	i;

	i = -1;
	if (!ist->zero)
		return ;
	if (ist->zero > cnt_digit_x(hx))
		ist->zero -= cnt_digit_x(hx);
	else
		ist->zero = 0;
	while (++i < ist->zero)
		write(1, "0", 1);
}

int	puthex_int(unsigned int hx, int c, t_print *ist)
{
	int	i;

	i = -1;
	if (ist->pnt && hx && c == 'x')
		write(1, "0x", 2);
	if (ist->pnt && hx && c == 'X')
		write(1, "0X", 2);
	if (ist->dash)
	{
		puthex(hx, c);
		while (++i < ist->dash - cnt_digit_x(hx))
			write(1, " ", 1);
		if (ist->dash > cnt_digit_x(hx))
			return (ist->dash);
		return (cnt_digit_x(hx));
	}
	i = -1;
	while (++i < ist->prc - cnt_digit_x(hx))
		write(1, "0", 1);
	zero_x(hx, ist);
	puthex(hx, c);
	if (ist->prc > cnt_digit_x(hx))
		return (ist->sign + ist->prc + ist->zero + 2 * (ist->pnt && hx));
	return (ist->zero + cnt_digit_x(hx) + 2 * (ist->pnt && hx));
}
