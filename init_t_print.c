/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:05 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:28:53 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

void	init_t_print(t_print *nw)
{
	nw->prc = 0;
	nw->zero = 0;
	nw->pnt = 0;
	nw->dash = 0;
	nw->sign = 0;
	nw->perc = 0;
	nw->sp = 0;
}
