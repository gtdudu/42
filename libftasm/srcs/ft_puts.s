# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:35:45 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:41 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%define MACH_SYSCALL(nb) 0x2000000 | nb
%define STDOUT 1
%define WRITE 4

section .data
	null:
		.string db "(null)"
		.len equ $ - null.string

section .text
	global _ft_puts
	extern _ft_putchar

_ft_puts:
	mov rdx, 0
	cmp rdi, 0
	je isnull
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

isnull:
	mov rdi, STDOUT
	lea rsi, [rel null.string]
	mov rdx, null.len
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	mov rdi, 10
	call _ft_putchar
	ret
