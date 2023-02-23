/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:53 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:26:20 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

void	mng_flag(const char **f, t_print *ist)
{
	int	tmp_cnd;

	if (**f == '+')
		ist->sign++;
	if (**f == ' ')
		ist->sp++;
	if (**f == '0' && !ist->dash)
		ist->zero = ft_atoi(*f);
	if (**f == '.')
	{
		ist->prc = ft_atoi(*f + 1);
		if (!ist->prc)
			ist->prc = -1;
	}
	if (**f == '#')
		ist->pnt++;
	if (**f == '-')
		ist->dash = ft_atoi(*f + 1);
	tmp_cnd = (!ist->dash && !ist->prc && !ft_isdigit(*(*f - 1)));
	if (ft_isdigit(**f) && **f != '0' && tmp_cnd)
		ist->zero = ft_atoi(*f);
}
