# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/02/15 01:05:02 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      ft_cd.c \
      ft_dup_env.c \
      ft_mod_env.c \
      ft_path_call.c \
      ft_setenv.c \
      ft_unsetenv.c \
      ft_shell_tools.c \
	  ft_cd_sub.c \
	  ft_signal.c 

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
	@echo "\033[31mft_minishell1 objects deleted\033[0m"

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

re : fclean all
