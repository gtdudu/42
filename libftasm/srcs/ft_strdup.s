# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 13:22:33 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:36:13 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern	_ft_memcpy

_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	mov rdx, rax
	call _malloc
	mov rdi, rax
	pop rsi
	call _ft_memcpy
	ret
