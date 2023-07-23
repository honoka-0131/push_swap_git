# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmakida <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 21:01:18 by hmakida           #+#    #+#              #
#    Updated: 2023/01/31 20:42:17 by hmakida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putnbr_fd.c ft_strjoin.c ft_itoa.c ft_substr.c ft_putendl_fd.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM	= rm -f
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	ar -r $(NAME) $(OBJS) 

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(RM) $(NAME)

re : fclean all

all : $(NAME)

.PHONY:			all clean fclean re
