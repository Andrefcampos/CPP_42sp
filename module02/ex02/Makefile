# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 14:08:37 by andrefil          #+#    #+#              #
#    Updated: 2024/07/09 14:08:54 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------ NAME ---------------------#
NAME		:=	Fixed

#------------------ COMPILER -----------------#
CC			:=	c++ -std=c++98

#------------------ INCLUDES ------------------#
INCLUDES	:=	$(addprefix -I, includes/)

#------------------ FLAGS --------------------#
CPP_FLAGS	:=	$(INCLUDES) -Wall -Werror -Wextra

#------------------ FILES --------------------#
SRC_FILES	+=	$(addprefix ./srcs/, \
				main.cpp \
				Fixed.cpp )

#------------------ OBJ ---------------------#
OBJS_DIR	:=	./objs/
OBJS		:=	$(patsubst ./srcs/%.cpp, $(OBJS_DIR)%.o, $(SRC_FILES))

#------------------ RULES ---------------------#
all: $(NAME)

$(OBJS_DIR)%.o: ./srcs/%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $< -> $@"
	@$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Linking $(NAME)"
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@echo "Objects clean: $(OBJS)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Binary clean: $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
