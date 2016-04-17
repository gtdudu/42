# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 17:33:38 by tdurand           #+#    #+#              #
#    Updated: 2015/04/20 17:55:19 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%define MACH_SYSCALL(nb)		0x2000000 | nb
%define READ					3
%define WRITE					4
%define STDOUT					1
%define BUFF_SIZE				1024

section .data
	error:
		.string db "wrong fd", 10

section .bss
	buffer: resb BUFF_SIZE

section .text
	global _ft_cat
	extern _ft_bzero
	extern _ft_putstr

_ft_cat:
	mov r12, rdi

_loop:
	lea rdi, [rel buffer]
	mov rsi, BUFF_SIZE
	call _ft_bzero
	mov rdi, r12
	lea rsi, [rel buffer]
	mov rdx, BUFF_SIZE
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc print_error
	cmp rax, 0x00
	je end
	lea rdi, [rel buffer]
	mov rdx, rax
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp _loop


print_error:
	lea rdi, [rel error.string]
	call _ft_putstr

end:
	ret
