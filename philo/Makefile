# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 08:01:55 by ldufour           #+#    #+#              #
#    Updated: 2023/11/20 08:47:57 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/main.c \

OBJ = $(SRC:.c=.o)

	
OBJB = $(SRCB:c=o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

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
