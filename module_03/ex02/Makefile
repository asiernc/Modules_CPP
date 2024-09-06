# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 20:37:28 by anovio-c          #+#    #+#              #
#    Updated: 2024/09/06 19:19:33 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = repetitiveWork

INC_DIR	= inc/
INC		= $(INC_DIR)ClapTrap.hpp \
		  $(INC_DIR)ScavTrap.hpp \
		  $(INC_DIR)FragTrap.hpp

SRC_DIR	= srcs/
SRC		= $(SRC_DIR)ClapTrap.cpp \
		  $(SRC_DIR)main.cpp \
		  $(SRC_DIR)ScavTrap.cpp \
		  $(SRC_DIR)FragTrap.cpp

OBJ_DIR	= objs/
OBJ		= $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
DEP 	= $(OBJ:.o=.d)
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP

# Colored output
ERASE	= \033[2K\r
BLUE	= \033[34m
YELLOW	= \033[33m
GREEN	= \033[32m
END		= \033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)$(OBJ_DIR) directory created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(BLUE)-> $<$(END)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) made$(END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Objects removed$(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) removed$(END)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re