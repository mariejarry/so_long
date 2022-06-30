SRCS =	so_long.c			\
		parse_map.c			\
		errors.c			\
		moves.c				\
		print.c				\


NAME = so_long

OBJS = $(SRCS:.c=.o) 

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

.c.o :
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "So_long Done !\n"
	@$(MAKE) -C libft
	@$(CC) $(CC_FLAGS) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all