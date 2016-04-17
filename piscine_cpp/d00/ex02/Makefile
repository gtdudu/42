# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 11:32:40 by tdurand           #+#    #+#              #
#    Updated: 2016/04/04 18:02:03 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	      = a.out

CXX           = clang++
FLAGS    			= -Wall -Wextra -Werror
RM            = rm -rf

SRCS          = tests.cpp \
				Account.class.cpp

OBJS          = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)
	@echo "\033[1;32m>>> $(NAME) <<<\033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[4;1;34mClean $(NAME) OBJS     >>\033[0m  \033[1;32mok.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[4;1;34mClean $(NAME)          >>\033[0m  \033[1;32mok.\033[0m"

re: fclean all

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ -c $<
