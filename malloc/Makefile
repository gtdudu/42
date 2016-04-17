# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/03/26 12:11:19 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_malloc.c \
	  ft_print_tabs.c \
	  ft_manage_tiny.c \
	  ft_manage_small.c \
	  ft_manage_large.c \
	  ft_free_tiny.c \
	  ft_free_small.c \
	  ft_free_large.c \
	  ft_free.c \
	  ft_realloc.c

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) -shared -o $(NAME) $(OBJ) $(LIB)
	@ln -s $(NAME) libft_malloc.so
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
	@/bin/rm -f libft_malloc.so
	@echo "\033[31m$(NAME) objects deleted\033[0m"

fclean : allclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

allclean :
	@make -C libft/ fclean
	@/bin/rm -f libft_malloc.so
	@/bin/rm -f $(OBJ)
	@echo "\033[31m$(NAME) objects deleted\033[0m"

re : fclean all
