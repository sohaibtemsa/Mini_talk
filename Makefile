# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 12:10:07 by stemsama          #+#    #+#              #
#    Updated: 2023/02/19 12:31:15 by stemsama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVEUR = server

CLIENT_b = client_b
SERVEUR_b = server_b

CC = cc
FLAGS =  -Wall -Werror -Wextra

SRC1 = client.c utils.c
SRC2 = server.c utils.c

SRCB1 = client_bonus.c utils.c
SRCB2 = server_bonus.c utils.c


all : $(CLIENT) $(SERVEUR)

$(CLIENT) : $(SRC1) minitalk.h
	$(CC) $(FLAGS) $(SRC1) -o $(CLIENT)

$(SERVEUR) : $(SRC2) minitalk.h
	$(CC) $(FLAGS) $(SRC2) -o $(SERVEUR)


bonus : $(CLIENT_b) $(SERVEUR_b)

$(CLIENT_b) : $(SRCB1) minitalk.h
	$(CC) $(FLAGS) $(SRCB1) -o $(CLIENT_b)

$(SERVEUR_b) : $(SRCB2) minitalk.h
	$(CC) $(FLAGS) $(SRCB2) -o $(SERVEUR_b)


clean :
	rm -f $(CLIENT) $(SERVEUR) $(SERVEUR_b) $(CLIENT_b)

fclean : clean
	rm -f $(CLIENT) $(SERVEUR) $(SERVEUR_b) $(CLIENT_b)

re : fclean all 

.PHONY: clean fclean re all
