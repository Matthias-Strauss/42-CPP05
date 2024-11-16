# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 17:43:47 by mstrauss          #+#    #+#              #
#    Updated: 2024/11/16 20:52:47 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bureaucrat

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++17
INC			=   -I$(CURDIR)

SRC 		=	main.cpp\
				Bureaucrat.cpp\
				Exceptions.cpp

HEADER		=	Bureaucrat.hpp\
				Exceptions.hpp
OBJ_DIR		=	/obj
OBJ 		=	 $(SRC:.cpp=.o)

RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
