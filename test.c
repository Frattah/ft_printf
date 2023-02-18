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
	int x = ft_printf("Test% +d fichissimo!\n", 432);
	printf("%+d\n", 432);
}
