# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:48:04 by khbouych          #+#    #+#              #
#    Updated: 2023/01/03 18:24:12 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_F =	server.c lib/ft_putnbr.c
C_F = client.c lib/ft_putnbr.c lib/ft_atoi.c

S_OB = $(S_F:.c=.o)
C_OB = $(C_F:.c=.o)

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)
bonus: $(SERVER) $(CLIENT)

$(SERVER): $(S_OB)
	@cc -Werror -Wextra -Wall $(S_OB) -o $(SERVER)

$(CLIENT) : $(C_OB)
	@cc -Werror -Wextra -Wall $(C_OB) -o $(CLIENT)

%.o:%.c minitalk.h
	cc -Werror -Wextra -Wall -c $< -o $@

clean:
	@rm -f  $(S_OB) $(C_OB)

fclean: clean
	@rm -f  $(SERVER) $(CLIENT)

re: fclean all clean
