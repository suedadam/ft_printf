# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyed <asyed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 01:09:10 by asyed             #+#    #+#              #
#    Updated: 2017/11/07 01:10:20 by asyed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -I libft/

SRC = ft_printf.c \
		parse.c \
		utils.c \
		conversions.c \
		flags.c \

SRC_OBJ = $(subst .c,.o, $(SRC))		

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

%.o: %.c \
	@gcc $(CFLAGS) -c $? -o $@

$(NAME): $(SRC_OBJ)
	@/bin/rm -f $(NAME)
	@ar rcs $(NAME) $(SRC_OBJ)
	@ranlib $(NAME)


clean:
	@make -C libft clean
	@rm -f $(SRC_OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all