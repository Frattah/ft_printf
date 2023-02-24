/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuns_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:10:08 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:26 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

void	putuns(unsigned int un)
{
	if (un < 10)
		ft_putchr_fd("0123456789"[un], 1);
	else
	{
		putuns(un / 10);
		putuns(un % 10);
	}
}

int	cnt_digit_u(unsigned int un)
{
	int	ln;

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

void	zero_un(unsigned int un, t_print *ist)
{
	int	i;

	i = -1;
	if (!ist->zero)
		return ;
	if (ist->zero > cnt_digit_u(un))
		ist->zero -= cnt_digit_u(un);
	else
		ist->zero = 0;
	while (++i < ist->zero)
		write(1, "0", 1);
}

int	putuns_int(unsigned int un, t_print *ist)
{
	int	i;

	i = -1;
	if (ist->dash)
	{
		putuns(un);
		while (++i < ist->dash - cnt_digit_u(un))
			write(1, " ", 1);
		if (ist->dash > cnt_digit_u(un))
			return (ist->dash);
		return (cnt_digit_u(un));
	}
	zero_un(un, ist);
	i = -1;
	while (++i < ist->prc - cnt_digit_u(un))
		write(1, "0", 1);
	putuns(un);
	if (ist->prc > cnt_digit_u(un))
		return (ist->sign + ist->prc + ist->zero);
	return (ist->zero + cnt_digit_u(un));
}
