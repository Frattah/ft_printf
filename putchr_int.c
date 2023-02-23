/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:41:15 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:43:11 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

size_t	putchr_int(int c, t_print *ist)
{
	int	i;

	i = 0;
	if (ist->zero)
	{
		while (++i < ist->zero - 1)
			write(1, " ", 1);
		return (ist->zero);
	}
	write(1, &c, 1);
	if (ist->dash)
	{
		i = -1;
		while (++i < ist->dash - 1)
			write(1, " ", 1);
		return (ist->dash);
	}
	return (1);
}
