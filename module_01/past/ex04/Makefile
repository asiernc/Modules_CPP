# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 12:45:47 by anovio-c          #+#    #+#              #
#    Updated: 2024/08/16 20:22:06 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sedIsForLosers

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re