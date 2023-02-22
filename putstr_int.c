#include "include/ft_printf.h"
#include "libft/libft.h"

size_t	putstr_int(char *s, s_print *ist)
{
  if (s != NULL)
  {
    if (ist->dash)
        for (int i = 0; i < ist->dash - 1; i++)
            write(1, " ", 1);
		return (write(1, s, ft_strlen(s)) + ist->dash);
  }
  ft_putstr_fd("(null)",1);
  return (6);
}