# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 20:24:35 by anovio-c          #+#    #+#              #
#    Updated: 2024/09/02 11:18:35 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombinator

SRC = 	Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ =	$(SRC:.cpp=.o)
CC =	g++
RM =	rm -f
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

all:	$(NAME)

%.o : %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re 