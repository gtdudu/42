# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/26 15:10:51 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:34:23 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_bzero

_ft_bzero:
	cmp rdi, 0
	je end
	mov rbx, rdi
	mov rax, rsi

bzero_loop:
	cmp rax, 0
	jle end
	mov [rbx], byte 0x00
	inc rbx
	dec rax
	jmp bzero_loop

end:
	ret
