# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 16:34:16 by andrefil          #+#    #+#              #
#    Updated: 2024/06/28 01:34:24 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	megaphone

CC			:=	c++

CPP_FLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRC_FILES	+=	./megaphone.cpp

OBJS		:=	$(SRC_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
