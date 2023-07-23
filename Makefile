NAME = push_swap
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
SRC = main.c start.c compression.c
OBJ = $(SRC: .c=.o)
CC = cc
CFRAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFRAGS) $^ -o $@
%.o%.c: $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFRAGS) $^ -o $@
$(LIBFT):
	$(MAKE) -C ./libft
$(PRINTF):
	$(MAKE) -C ./printf
clean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./printf fclean
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
