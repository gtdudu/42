# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/31 15:50:06 by tdurand           #+#    #+#              #
#    Updated: 2015/03/31 17:32:33 by tdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_memcmp

_ft_memcmp:
	mov r12, rdi
	add r12, rsi
	jz end
	mov rcx, rdx
	repne cmpsb
	ret

end:
	mov rax, 0
	ret
