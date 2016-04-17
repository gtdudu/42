# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/02/03 13:06:09 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

SRC = main.c \
	  ft_pixel_put_to_image.c \
	  ft_move.c \
	  ft_initiate.c \
	  ft_mainprog.c \
	  ft_hook.c \
	  ft_draw_line.c \
	  ft_check_input.c \

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) libft/libft.a 
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
	@echo "\033[31mwolf3d objects deleted\033[0m"

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

re : fclean all
