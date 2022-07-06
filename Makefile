# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 16:15:20 by hepiment          #+#    #+#              #
#    Updated: 2022/07/05 18:19:59 by hepiment         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_to_hex.c\
			ft_printf_utils.c\


OBJS	=	ft_printf.o\
			ft_to_hex.o\
			ft_printf_utils.o\


HEADER	=	ft_printf.h

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	$(SRCS)
		clang $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(HEADER)
		ar rcs $@ $^

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY: all clean fclean re