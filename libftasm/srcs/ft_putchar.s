# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putchar.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 16:43:25 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:36:55 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .text
		global	_ft_putchar

_ft_putchar:
	push rbx
	mov	[rbx], rdi
	mov	rsi, rbx
	mov	rdi, STDOUT
	mov	rdx, 1
	mov	rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	ret
