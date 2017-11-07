#Fix this shit pls
NAME = fillit

# CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I libft/

SRC = ft_printf.c

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@gcc -c $(SRC) $(CFLAGS)
	@ar rc printf.a ft_printf.o
	@ranlib printf.a


clean:
	@make -C libft clean
	@rm -f *.o
	@rm -f *.a
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all