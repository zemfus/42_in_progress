# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airis <airis@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 16:11:40 by airis             #+#    #+#              #
#    Updated: 2021/12/16 21:42:09 by airis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
HED		=	ft_printf.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar -rcs

SRC		=	ft_printf.c ft_print_flags.c ft_itoa.c ft_utoa.c

OBJS		=	$(SRC:%.c=%.o)

all: $(NAME) $(HED)

$(NAME): $(OBJS)
			$(AR) $(NAME) $(OBJS)


%.o : %.c $(HED)
			$(CC) $(CFLAGS) -c $< -o $@


clean :
			@rm -rf $(OBJS)


fclean :  clean
			@rm -rf $(NAME)


re : fclean all

.PHONY: all clean fclean re