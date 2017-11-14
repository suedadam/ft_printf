# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyed <asyed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 01:09:10 by asyed             #+#    #+#              #
#    Updated: 2017/11/13 17:14:36 by asyed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Werror -Wextra

SRC = ft_printf.c \
		parse.c \
		utils.c \
		conversions.c \
		num_fetch.c \
		flags.c \
		libft/ft_tolower.c \
		libft/ft_strcmp.c \
		libft/ft_putstr.c \
		libft/ft_putnbr.c \
		libft/ft_strcpy.c \
		libft/ft_putchar.c \
		libft/ft_bzero.c \
		libft/ft_atoi.c \
		libft/ft_isdigit.c \
		libft/ft_isspace.c \
		libft/ft_isupper.c \
		libft/ft_memset.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putchar_fd.c \
		libft/ft_strlen.c \
		libft/ft_uputnbr_fd.c \
		libft/ft_uputnbr.c \


SRC_OBJ = $(subst .c,.o, $(SRC))

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

$(NAME): $(SRC_OBJ)
	/bin/rm -f $(NAME)
	ar rcs $(NAME) $(SRC_OBJ)

clean:
	/bin/rm -f $(SRC_OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: clean all