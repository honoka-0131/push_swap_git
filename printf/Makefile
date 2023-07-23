# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmakida <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:13:26 by hmakida           #+#    #+#              #
#    Updated: 2023/03/01 12:08:43 by hmakida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa.c ft_strlen.c printf_ptr_ux.c 
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -r $(NAME) $(OBJS)

clean :
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY:		all clean fclean re
