# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 12:45:47 by anovio-c          #+#    #+#              #
#    Updated: 2024/08/16 20:22:22 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl2.0

HEADERS = Harl.hpp
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic


all: $(NAME)

%.o : %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re