SRCS	=	ft_printf.c cnt_return.c convert.c	init_s_print.c	putnbr_int.c	putstr_int.c	putchr_int.c \
			putptr_int.c	puthex_int.c	putuns_int.c	mng_flag.c	is_flag.c
OBJS	=	$(SRCS:.c=.o)

NAME	=	ft_printf.a

all:	$(NAME)

%.o: %.c
	@echo "\033[0;34mCompilo i file C ...\033[0m"
	@cc -Wall -Wextra -Werror -g -c $(SRCS)
	@echo "\033[0;32mCompilazione conclusa. \033[0m"

$(NAME): $(OBJS)
	@echo "\033[0;34mCreazione libreria ... \033[0m"
	@ar rcs -r $@ $?
	@echo "\033[1;32mCostruzione Completata con successo!!! \033[0m"

clean:
	@echo "\033[0;31mRimuovo tutti i file oggetto ...\033[0m\n"
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[0;31mRimozione libreria ...\033[0m\n"
	@rm -rf $(NAME)

re: fclean all