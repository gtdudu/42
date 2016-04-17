# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:04:03 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:34:47 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	_ft_isdigit

_ft_isdigit:
	mov rax, 0
	cmp rdi, 48
	jl end
	cmp rdi, 57
	jg end
	mov rax, 1

end:
	ret
