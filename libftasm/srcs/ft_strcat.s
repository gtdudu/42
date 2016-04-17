# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/26 15:18:16 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 19:08:49 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_strcat

_ft_strcat:
	xor r12, r12
	xor r13, r13
	xor r14, r14
	mov r12, rdi
	mov r13, rsi
	push rdi
	cmp rdi, 0
	je end

strcat_loop:
	cmp byte[r12], 0
	je strcat_add
	inc r12
	jmp strcat_loop

strcat_add:
	mov r14, [r13]
	mov [r12], r14
	cmp [r12], byte 0
	je end
	inc r12
	inc r13
	jmp strcat_add

end:
	pop rax
	ret
