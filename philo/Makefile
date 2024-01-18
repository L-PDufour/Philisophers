# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 08:01:55 by ldufour           #+#    #+#              #
#    Updated: 2024/01/17 13:58:54 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	src/utils.c \
		src/parsing.c \
		src/time.c \
		src/main.c   

OBJ = $(SRC:.c=.o)
	
CC = cc

CFLAGS = -g

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all:	$(NAME)

clean:	
		@rm -f $(OBJ) 

fclean:	clean
		@rm -f $(NAME) 

re:		fclean all

run: all
	@./$(NAME)

.PHONY: all, clean, fclean, re, libmlx
