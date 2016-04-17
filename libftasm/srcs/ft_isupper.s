# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 11:57:00 by tdurand           #+#    #+#              #
#    Updated: 2015/03/27 11:59:43 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_isupper

section	.text

_ft_isupper:
	mov rax, 0
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jg end
	mov rax, 1

end:
	ret
