NAME = push_swap
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
SRC = main.c start.c compression.c list.c
OBJ = $(SRC:%.c=%.o)
CC = cc
CFRAGS = -Wall -Wextra -Werror 
# CFRAGS += -fsanitize=address
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFRAGS) $^ -o $@

all: $(NAME)

%.o: %.c
	$(CC) $(CFRAGS) -c $^ -o $@
$(LIBFT):
	$(MAKE) -C ./libft
$(PRINTF):
	$(MAKE) -C ./printf
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
