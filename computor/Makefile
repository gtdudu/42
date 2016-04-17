# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/04/21 14:33:32 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  ft_routine.c \
	  ft_manage.c \
	  ft_resolve.c \
	  ft_display.c \
	  ft_math.c \

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 
	@echo "!"
	@echo "$(NAME) compiled\033[0m"

libft :
	@make -C libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) -I./includes/ -I./libft/includes $<
	@printf "\033[32m."

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mcomputorv1 objects deleted\033[0m"

fclean : allclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

allclean :
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mcomputorv1 objects deleted\033[0m"

re : fclean all
