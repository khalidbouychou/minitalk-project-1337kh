# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:48:04 by khbouych          #+#    #+#              #
#    Updated: 2022/12/30 21:01:43 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

INC = minitalk.h

CSRC = client.c
CSRC_OBJ = ${CSRC:.c=.o}

SSRC = server.c
SSRC_OBJ = ${SSRC:.c=.o}

CNAME = client
CBNAME = client_bonus
SNAME = server
SBNAME = server_bonus

BNSSERVER = server_bonus.c
SBNUS_OBJ = ${BNSSERVER:.c=.o}
BNSCLIENT = client_bonus.c
CBNUS_OBJ = ${BNSCLIENT:.c=.o}


all: $(CNAME) $(SNAME) 

$(CNAME): $(CSRC_OBJ) $(INC)
	@$(CC) $(FLAGS) $(CSRC_OBJ) -o $(CNAME)
$(SNAME): $(SSRC_OBJ) $(INC)
	@$(CC) $(FLAGS) $(SSRC_OBJ) -o $(SNAME)

clean:
	@rm -rf $(SSRC_OBJ) $(CSRC_OBJ) $(CBNUS_OBJ) $(SBNUS_OBJ)

fclean: clean
	@rm -rf $(CNAME) $(SNAME) $(CBNAME)  $(SBNAME)

bonus: $(CBNUS_OBJ) $(SBNUS_OBJ)
	@$(CC) $(FLAGS) $(CBNUS_OBJ) -o $(CBNAME)
	@$(CC) $(FLAGS) $(SBNUS_OBJ) -o $(SBNAME)

re: fclean all