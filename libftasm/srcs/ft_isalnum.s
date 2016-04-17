# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 16:06:35 by tdurand           #+#    #+#              #
#    Updated: 2015/03/27 16:07:41 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 1
	je end
	call _ft_isdigit

end:
	ret
