/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:20:29 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/18 09:03:09 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	sum(int count, ...)
{
	int	sum;
	sum = 0;
	va_list	args;
	va_start(args, count);
	sum += va_arg(args, int);
	va_end(args);
	return (sum);
}

int	main(void)
{
	printf("%d\n",ft_printf(" %011x ", LONG_MAX));
	printf("%d\n",printf(" %011x ", LONG_MAX));

	printf("%d\n",ft_printf(" %01X ", 0));
	printf("%d\n",printf(" %01X ", 0));

	printf("%d\n",ft_printf(" %011X ", LONG_MAX));
	printf("%d\n",printf(" %011X ", LONG_MAX));

	printf("%d\n",ft_printf(" %011x ", LONG_MAX));
	printf("%d\n",printf(" %011x ", LONG_MAX));
	
}
