/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:00:57 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:31:29 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int	putstr(char *s, int prc)
{
	int	i;

	i = 0;
	if (prc == 0)
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	while (*s && i < prc)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

size_t	putstr_int(char *s, t_print *ist)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (putstr ("(null)", 6));
	if (ist->zero && !ist->prc)
	{
		while (++i < ist->zero - (int) ft_strlen(s))
			write(1, " ", 1);
		putstr(s, ist->prc);
		if (ft_strlen(s) > (size_t) ist->zero)
			return (ft_strlen(s));
		return (ist->zero);
	}
	if (ist->dash)
	{
		putstr(s, ist->prc);
		i = -1;
		while (++i < ist->dash - (int) ft_strlen(s))
			write(1, " ", 1);
		if (ft_strlen(s) > (size_t) ist->dash)
			return (ft_strlen(s));
		return (ist->dash);
	}
	return (putstr(s, ist->prc));
}
