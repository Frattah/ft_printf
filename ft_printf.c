/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:04 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:32:01 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int		ln;
	t_print	*ist;

	ist = (t_print *)malloc(sizeof(t_print));
	va_start(ist->args, format);
	if (!ist)
		return (-1);
	init_t_print(ist);
	ist->ln = 0;
	cnt_return(format, ist);
	va_end(ist->args);
	ln = ist->ln;
	free(ist);
	return (ln);
}
