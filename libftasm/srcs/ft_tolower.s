# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:33:30 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:30 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	_ft_tolower
	extern	_ft_isupper

_ft_tolower:
	call _ft_isupper
	cmp rax, 0
	je notup
	add rdi, 32
	mov rax, rdi
	jmp end

notup:
	mov rax, rdi
	jmp end

end:
	ret
