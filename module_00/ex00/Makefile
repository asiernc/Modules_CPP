# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 20:37:05 by anovio-c          #+#    #+#              #
#    Updated: 2024/08/12 15:12:56 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone

SRC = 	Megaphone.cpp
OBJ =	$(SRC:.cpp=.o)
CC =	g++
RM =	rm -f
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

all:	$(NAME)

%.o : %.cpp Makefile
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re 