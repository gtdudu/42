# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/06/08 02:08:57 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME  	      = lem-in

CC            = gcc
ALL_CFLAGS    = -Wall -Wextra -Werror
RM            = rm -rf

SRCS_DIR	  = srcs
OBJS_DIR      = objs
INCS_DIR      = includes
LIBFT         = libft
S             = main.c \
			    ft_clear.c \
			    ft_cpy.c \
			    ft_find_best_path.c \
			    ft_get.c \
			    ft_init.c \
			    ft_print.c \
			    ft_read_input.c \
				ft_smooth.c \

SRCS        = $(addprefix $(SRCS_DIR)/, $S)
OBJS        = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(ALL_CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft
	@echo "\033[1;32m>>> lem-in ok <<<\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(ALL_CFLAGS) -I$(INCS_DIR) -I$(LIBFT)/$(INCS_DIR) -c $< -o $@
	@echo "\033[A\033[K\033[A"

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT) clean
	@echo "\033[4;1;34mClean $(NAME) OBJS     >>\033[0m  \033[1;32mok.\033[0m"

fclean: clean
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)
	@echo "\033[4;1;34mClean $(NAME)          >>\033[0m  \033[1;32mok.\033[0m"

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
