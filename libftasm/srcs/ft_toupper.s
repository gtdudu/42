# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:20:57 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:26 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	_ft_toupper
	extern	_ft_islower

_ft_toupper:
	call _ft_islower
	cmp rax, 0
	je notlow
	sub rdi, 32
	mov rax, rdi
	jmp end

notlow:
	mov rax, rdi
	jmp end

end:
	ret
