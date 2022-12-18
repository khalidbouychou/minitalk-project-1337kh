# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 18:21:23 by khbouych          #+#    #+#              #
#    Updated: 2022/12/18 18:24:21 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC    = gcc
FLAGS    = -Wall -Wextra -Werror

SRV    = server
CLI    = client

SRV_C = $(SRV:=.c)
CLI_C = $(CLI:=.c)

SRV_O    = $(SRV:=.o)
CLI_O = $(CLI:=.o)

LIB = ft_printf/libftprintf.a
LIBDIR    = ft_printf

HEADER = minitalk.h

all: $(LIB) $(SRV) $(CLI)

$(SRV): $(SRV_O) $(HEADER)
	@ $(CC) $(FLAGS) -I $(HEADER) $(LIB) $(SRV_O) -o $@

$(CLI): $(CLI_O) $(HEADER)
	@ $(CC) $(FLAGS) -I $(HEADER) $(LIB) $(CLI_O) -o $@

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@ $(MAKE) -C $(LIBDIR)

clean:
	@ $(MAKE) clean -C $(LIBDIR)
	@ rm -rf $(SRV_O) $(CLI_O)

fclean: clean
	@ $(MAKE) fclean -C $(LIBDIR)
	@ rm -rf $(SRV) $(CLI)

re: fclean all