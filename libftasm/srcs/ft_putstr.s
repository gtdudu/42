# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 18:10:19 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:37:01 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%define MACH_SYSCALL(nb) 0x2000000 | nb
%define STDOUT 1
%define WRITE 4

section .text
	global _ft_putstr
	extern _ft_putchar

_ft_putstr:
	mov rdx, 0
	cmp rdi, 0
	je end
	push rdi
	mov rsi, rdi

loop:
	cmp byte[rsi], 0
	je notnull
	inc rsi
	inc rdx
	jmp loop

notnull:
	pop rsi
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp end

end:
	mov rax, 0
	ret
