# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 18:36:15 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:50 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_strlen

_ft_strlen:
	mov rsi, rdi
	mov rcx, -1
	mov rax, 0
	cld
	repnz scasb
	mov rax, -2
	sub rax, rcx
	ret
