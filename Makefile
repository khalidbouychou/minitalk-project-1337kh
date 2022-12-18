# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:48:04 by khbouych          #+#    #+#              #
#    Updated: 2022/12/18 12:09:04 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rc
RM = rm -f
FILES = ft_printf.c ft_putchar.c ft_print_str.c ft_print_number.c  ft_print_hex_upper.c  ft_print_hex_lower.c  ft_print_adr_memory.c  ft_print_unsigned_format.c ft_strlen.c ft_atoi.c
OBJ = $(FILES:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all