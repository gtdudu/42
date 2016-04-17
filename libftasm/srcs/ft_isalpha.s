# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 11:23:15 by tdurand           #+#    #+#              #
#    Updated: 2015/03/27 12:19:16 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_isalpha
	extern	_ft_isupper
	extern	_ft_islower

_ft_isalpha:
	call _ft_isupper
	cmp rax, 1
	je end
	call _ft_islower

end:
	ret
