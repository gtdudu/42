# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 19:34:30 by tdurand           #+#    #+#              #
#    Updated: 2015/03/27 20:12:46 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_memset

_ft_memset:
	push rdi
	mov r13, rsi
	mov rsi, rdi
	mov rcx, rdx
	mov rax, r13
	rep stosb
	pop rax
	ret
