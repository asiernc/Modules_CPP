# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 20:37:28 by anovio-c          #+#    #+#              #
#    Updated: 2024/08/29 20:06:07 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap

INC_DIR =	inc/
INC		=	inc/ClapTrap.hpp

SRC 	=	srcs/ClapTrap.cpp \
			srcs/main.cpp

OBJ_DIR =	objs/
OBJ 	= 	$(SRC:srcs/%.cpp=$(OBJ_DIR)%.o)
CC 		= 	g++
CFLAGS	= 	-Wall -Wextra -Werror -std=c++98 -pedantic

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: srcs/%.cpp Makefile inc/ClapTrap.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)-> $<$(END)\n"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) made$(END)\n"

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Objects removed$(END)\n"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) removed$(END)\n"

re:			fclean $(NAME)

.PHONY:		all clean fclean re
