# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 19:29:06 by anovio-c          #+#    #+#              #
#    Updated: 2024/08/05 21:14:01 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dontknow


SRC = 	tests.cpp Acount.cpp
OBJ =	$(SRC:.cpp=.o)
CC =	g++
RM =	rm -f
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re 