/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:20:52 by frmonfre          #+#    #+#             */
/*   Updated: 2023/02/23 15:30:45 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct T_PRINT
{
	va_list	args;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	size_t	ln;
	int		sign;
	int		perc;
	int		sp;
}	t_print;

int		ft_printf(const char *format, ...);

int		cnt_digit_d(int n);

void	cnt_return(const char *format, t_print *ist);

void	init_t_print(t_print *nw);

size_t	convert(const char **f, t_print *ist);

size_t	putnbr_int(int nb, t_print *ist);

size_t	putstr_int(char *s, t_print *ist);

size_t	putchr_int(int c, t_print *ist);

size_t	putptr_int(unsigned long long ptr, t_print *ist);

int		puthex_int(unsigned int hx, int c, t_print *ist);

int		putuns_int(unsigned int un, t_print *ist);

void	mng_flag(const char **f, t_print *ist);

int		is_flag(int c);

#endif
