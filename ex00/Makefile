# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 17:43:47 by mstrauss          #+#    #+#              #
#    Updated: 2025/04/16 18:31:04 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bureaucrat

CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -g -std=c++17
INC			=   -I$(CURDIR)

SRC 		=	main.cpp\
				Bureaucrat.cpp\

HEADER		=	Bureaucrat.hpp
OBJ_DIR		=	obj
OBJ 		=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

RM			=	rm -rf

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
