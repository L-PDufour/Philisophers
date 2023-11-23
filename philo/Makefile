# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 08:01:55 by ldufour           #+#    #+#              #
#    Updated: 2023/11/23 08:22:34 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	src/utils.c \
		src/parsing.c \
		src/main.c   

OBJ = $(SRC:.c=.o)
	
CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

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
