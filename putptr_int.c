/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:35:05 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:37:22 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int	cnt_ptr_dgt(unsigned long long ptr)
{
	int	ln;

	ln = 0;
	while (ptr > 0)
	{
		ln++;
		ptr /= 16;
	}
	return (ln);
}

void	putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
	}
	else
		ft_putchr_fd("0123456789abcdef"[ptr], 1);
}

size_t	putptr_int(unsigned long long ptr, t_print *ist)
{
	size_t	ln;
	int		i;

	i = -1;
	ln = 0;
	ln += write(1, "0x", 2);
	if (ptr == 0)
		ln += write(1, "0", 1);
	else
	{
		if (ist->dash)
		{
			putptr(ptr);
			while (++i < ist->dash - cnt_ptr_dgt(ptr) - 2)
				write(1, " ", 1);
			if (2 + cnt_ptr_dgt(ptr) < ist->dash)
				return (ist->dash);
			return (2 + cnt_ptr_dgt(ptr));
		}
		ln += cnt_ptr_dgt(ptr);
		putptr(ptr);
	}
	return (ln);
}
