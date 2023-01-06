# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:48:04 by khbouych          #+#    #+#              #
#    Updated: 2023/01/06 15:33:25 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_F =	man/server.c  man/lib/ft_putnbr.c
C_F = man/client.c  man/lib/ft_atoi.c

S_F_B = bonus/server_bonus.c bonus/lib_bonus/ft_putnbr_bonus.c
C_F_B = bonus/client_bonus.c  bonus/lib_bonus/ft_atoi_bonus.c

S_OB = $(S_F:.c=.o)
C_OB = $(C_F:.c=.o)
SB_OB = $(S_F_B:.c=.o)
CB_OB = $(C_F_B:.c=.o)

SERVER = output/server
CLIENT = output/client
SERVER_BONUS = output/server_bonus
CLIENT_BONUS = output/client_bonus

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(S_OB)
	@cc -Werror -Wextra -Wall $(S_OB) -o $(SERVER)

$(SERVER_BONUS): $(SB_OB)
	@cc -Werror -Wextra -Wall $(SB_OB) -o $(SERVER_BONUS)

$(CLIENT) : $(C_OB)
	@cc -Werror -Wextra -Wall $(C_OB) -o $(CLIENT)

$(CLIENT_BONUS) : $(CB_OB)
	@cc -Werror -Wextra -Wall $(CB_OB) -o $(CLIENT_BONUS)

%.o:%.c man/minital bonus/minitalk_bonus.hk.h
	@cc -Werror -Wextra -Wall -c $< -o $@

clean:
	@rm -f  $(S_OB) $(C_OB) $(CB_OB)  $(SB_OB)

fclean: clean
	@rm -f  $(SERVER) $(CLIENT)  $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all clean
