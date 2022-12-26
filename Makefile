# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 18:21:23 by khbouych          #+#    #+#              #
#    Updated: 2022/12/26 14:28:37 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS    = -Wall -Wextra -Werror

SRV    = server
CLI    = client
B_CLI = client_bonus
B_SRV = server_bonus

OB_CLI = $(B_CLI:=.o)
OB_SRV = $(B_SRV:=.o)

SRV_C = $(SRV:=.c)
CLI_C = $(CLI:=.c)

SRV_O    = $(SRV:=.o)
CLI_O = $(CLI:=.o)

LIB = ft_printf/libftprintf.a
LIBDIR    = ft_printf

HEADER = minitalk.h

all: $(LIB) $(SRV) $(CLI)

$(SRV): $(SRV_O) $(HEADER)
	@ cc $(FLAGS) -I $(HEADER) $(LIB) $(SRV_O) -o $@

$(CLI): $(CLI_O) $(HEADER)
	@ cc $(FLAGS) -I $(HEADER) $(LIB) $(CLI_O) -o $@

bonus: all $(OB_CLI) $(OB_SRV)
	@$(AR) $(HEADER) $(OB_CLI) $(OB_SRV)
	
%.o: %.c
	@ cc $(FLAGS) -c $< -o $@

$(LIB):
	@ $(MAKE) -C $(LIBDIR)

clean:
	@ $(MAKE) clean -C $(LIBDIR)
	@ rm -rf $(SRV_O) $(CLI_O)

fclean: clean
	@ $(MAKE) fclean -C $(LIBDIR)
	@ rm -rf $(SRV) $(CLI)

re: fclean all