/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:47:48 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:31:05 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

void	cnt_return(const char *format, t_print *ist)
{
	while (*format)
	{
		if (*format == '%')
			ist->ln += convert(&format, ist);
		else
			ist->ln += write(1, format, 1);
		format++;
	}
}
