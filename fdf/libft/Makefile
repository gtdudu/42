# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/06/02 18:32:16 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME        = libft.a

CC			= gcc
ALL_CFLAGS	= -Wall -Wextra -Werror
RM			= rm -rf

SRCS_DIR	= srcs
OBJS_DIR	= objs
INCS_DIR	= ./includes
S           = ft_atoi.c \
			  ft_check_char.c \
			  ft_bzero.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_islower.c \
			  ft_isupper.c \
			  ft_itoa.c \
			  ft_memalloc.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memdel.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putnbrl.c \
			  ft_putnbr_fd.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_strcat.c \
			  ft_strchr.c \
			  ft_strclr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlen.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strnequ.c \
			  ft_strnew.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strsplit.c \
			  ft_strstr.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_ctab_clear.c \
			  ft_ctab_len.c \
			  ft_ctab_display.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_lstnew.c \
			  ft_lstdelone.c \
			  ft_lstdel.c \
			  ft_lstadd.c \
			  ft_lstadd_back.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_lstprint_content.c \
			  ft_lstreverse.c \
			  ft_lstpush.c \
			  ft_lstpush_back.c \
			  ft_lstsize.c	\
			  get_next_line.c

SRCS        = $(addprefix $(SRCS_DIR)/, $S)
OBJS        = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;32m>>> libft.a ok <<<\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(ALL_CFLAGS) -I$(INCS_DIR) -c $< -o $@
	@echo "\033[A\033[K\033[A"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "\033[4;1;34mClean $(NAME) OBJS    >>\033[0m  \033[1;32mok.\033[0m"

fclean:
	@$(RM) $(NAME)
	@echo "\033[4;1;34mClean $(NAME)         >>\033[0m  \033[1;32mok.\033[0m"

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
