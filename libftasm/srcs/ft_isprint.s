# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:15:49 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:35:15 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	_ft_isprint

_ft_isprint:
	mov rax, 0
	cmp rdi, 32
	jl end
	cmp rdi, 126
	jg end
	mov rax, 1

end:
	ret
