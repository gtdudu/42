/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 17:54:50 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/20 17:56:30 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_cat(int fd);
int		ft_islower(int c);
int		ft_isupper(int c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
