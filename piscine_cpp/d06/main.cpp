/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rankierm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:46:20 by rankierm          #+#    #+#             */
/*   Updated: 2016/04/13 09:59:50 by rankierm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

struct		Data {
	std::string s1;
	int n;
	std::string s2;
};

std::string	*	randomString( void )
{
	int				i;
	int				j;
	char			l[] = "abcdefghIJKLMNOP";
	std::string		*s = new std::string;

	i = 0;
	while ( i < 8)
	{
		j = rand() % 10;
		std::string		c(1, l[j]);
		s->append( c );
		i++;
	}
	return (s);
}

void *		serialize( void )
{
	std::string		*s1;
	std::string		*s2;
	int				i = rand() % 10 + 48;
	char			*c;

	s1 =  randomString();
	s2 =  randomString();

	std::cout << std::string(28, '-') << std::endl;
	std::cout << s1->c_str() << " " << i << " " << s2->c_str() << std::endl;
	std::cout << std::string(28, '-') << std::endl;

	c = reinterpret_cast<char *>( &i );

	s1->append(c);
	s1->append(s2->c_str());

	delete s2;

	return reinterpret_cast<void *>(s1);
}

Data	* deserialize( void * raw)
{
	std::string			*data;
	Data				*ret = new Data;
	int					*i;
	char				*c;
	char				v;

	data = reinterpret_cast<std::string *>( raw );

	ret->s1 = data->substr(0, 8);
	ret->s2 = data->substr(9, 8);

	c = reinterpret_cast<char *>( data );
	v = *(c + 9);
	i = reinterpret_cast<int *>(&v);

	ret->n = *i;

	return ret;
}

int		main( void )
{
	srand( time(NULL) );

	void	*s = serialize();
	Data*	d = deserialize(s);

	std::cout << d->s1 << " " << d->n << " " << d->s2 << std::endl;

	delete d;
	return 0;
}
