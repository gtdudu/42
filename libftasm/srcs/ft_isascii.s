# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:12:55 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:08 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	_ft_isascii

_ft_isascii:
	mov rax, 0
	cmp rdi, 0
	jl end
	cmp rdi, 127
	jg end
	mov rax, 1

end:
	ret
