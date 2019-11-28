# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 19:18:53 by ashypilo          #+#    #+#              #
#    Updated: 2019/11/06 17:43:54 by ashypilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRCF = src/main.cpp src/Abstract.cpp src/Factory.cpp src/Command.cpp src/Exception.cpp
SRCDIR = ./
OBJS = $(addprefix $(SRCDIR), $(SRCF:.cpp=.o))
FLAGS = -std=c++14 -Wall -Wextra -Werror -g

all: $(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	clang++ $(FLAGS) -c -o $@ $< 

$(NAME): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re