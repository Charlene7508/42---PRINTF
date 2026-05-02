# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlepain <chlepain@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 17:24:45 by chlepain          #+#    #+#              #
#    Updated: 2026/05/02 17:58:17 by chlepain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_print_char.c \
      ft_print_hex.c \
      ft_print_int.c \
      ft_print_ptr.c \
      ft_print_str.c \
      ft_print_uint.c \
      ft_printf.c \
      ft_putchar.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
