#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct S_PRINT
{
    va_list args;
    int     wdt;
    int     prc;
    int     zero;
    int     pnt;
    int     dash;
    size_t  ln;
    int     sign;
    int     is_zero;
    int     perc;
    int     sp;
}   s_print;

int     ft_printf(const char *format, ...);

size_t  cnt_digit(int n);

void    cnt_return(const char *format, s_print *ist);

void    init_s_print(s_print *nw);

size_t  convert(const char **f, s_print *ist);

size_t  putnbr_int(int nb, s_print *ist);

size_t  putstr_int(char *s);

size_t  putchr_int(int c);

size_t  putptr_int(unsigned long long ptr);

size_t  puthex_int(unsigned long long hx);

size_t  putuns_int(unsigned int un);

void    mng_flag(int flg, s_print *ist);

int     is_flag(int c);

#endif