# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 11:59:50 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:37:12 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_islower

section	.text

_ft_islower:
	mov rax, 0
	cmp rdi, 97
	jl end
	cmp rdi, 122
	jg end
	mov rax, 1

end:
	ret
