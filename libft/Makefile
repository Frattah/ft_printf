# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 15:28:07 by frmonfre          #+#    #+#              #
#    Updated: 2023/01/29 13:32:47 by frmonfre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		ft_memcpy.c	\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_memchr.c	\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c	\
			ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c					ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putchr_fd.c

BRCS	=	ft_lstnew.c		ft_lstadd_front.c				ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c				ft_lstdelone.c	ft_lstclear.c	\
			ft_lstiter.c	ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BRCS:.c=.o)

NAME	=	libft.a

all:	$(NAME)

%.o: %.c
	@cc -Wall -Wextra -Werror -g -c $?

$(NAME): $(OBJS)
	@echo "\033[0;34mCompilo i file C ...\033[0m"
	@ar rcs -r $@ $?
	@echo "\033[1;32mCostruzione Completata con successo!!! \033[0m"

clean:
	@echo "\033[0;31mRimuovo tutti i file oggetto ...\033[0m\n"
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@echo "\033[0;31mRimozione libreria ...\033[0m\n"
	@rm -rf $(NAME)

re: fclean all

bonus: $(OBJS) $(BOBJS)
	@ar rcs -r $(NAME) $?
	@echo "\033[1;32mCostruzione Completata con successo!!! \033[0m"
