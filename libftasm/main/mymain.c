/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 10:25:37 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/20 17:55:07 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include "libfts.h"
#define RANDT	512
#define LONG	10000

/*****cat****/

static void	check_ft_cat(void)
{
	int		fd;

	fd = open("main/testcat", O_RDONLY);
	ft_cat(fd);
	close(fd);
}

/*****strdup****/

static int				check_ft_strdup(void)
{
	char		*ret1;
	char		*ret2;

	ret1 = strdup("");
	ret2 = ft_strdup("");
	assert(strcmp(ret1, ret2) == 0);
	free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	assert (strcmp(ret1, ret2) == 0);
	free(ret1);
	free(ret2);
	printf("%s\n", "------strdup OK--------");
	return (1);
}

/*********memcpy**********/

int					check_ft_memcpy(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2, *temp3;

	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			assert(memcmp(itab2, itab3, sizeof(itab)) == 0);
			assert(memcmp(ctab2, ctab3, sizeof(ctab)) == 0);
			assert(memcmp(ltab2, ltab3, sizeof(ltab)) == 0);
			++i;
		}
		++k;
	}
	printf("%s\n", "------memcpy OK--------");
	(void)temp;
	(void)temp2;
	(void)temp3;
	return (1);
}

/*********memset**********/
int					check_ft_memset(void)
{
	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j, k;
	void			*temp, *temp2;

	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				itab[j] = rand();
				ltab[j] = (unsigned long)rand() * LONG;
				j++;
			}
			memcpy(ctab2, ctab, sizeof(ctab));
			memcpy(itab2, itab, sizeof(itab));
			memcpy(ltab2, ltab, sizeof(ltab));
			temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
			assert(memcmp(itab, itab2, sizeof(itab)) == 0);
			temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			assert(memcmp(ctab, ctab2, sizeof(ctab)) == 0);
			temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			assert(memcmp(ltab, ltab2, sizeof(ltab)) == 0);
			++i;
		}
		++k;
	}
	printf("%s\n", "------memset OK--------");
	(void)temp;
	(void)temp2;
	return (1);
}

/****strlen****/

static int				check_ft_strlen(void)
{
	assert(strlen("") == ft_strlen(""));
	assert (strlen("abc") == ft_strlen("abc"));
	assert (strlen("a") == ft_strlen("a"));
	printf("%s\n", "------strlen OK--------");
	return (1);
}

/***puts****/

static void check_ft_puts()
{
	// printf("%d\n", ft_puts("lol"));
//	printf("%d", ft_puts(""));
	ft_puts("------puts OK------");
}

/*********tolowert**********/

int				check_ft_tolower(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(tolower(i) == tolower(i));
		i = i + 1;
	}
	printf("%s\n", "------tolower OK--------");
	return (1);
}

/*********toupper**********/

int				check_ft_toupper(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(toupper(i) == ft_toupper(i));
		i = i + 1;
	}
	printf("%s\n", "------toupper OK--------");
	return (1);
}

/*********is_print**********/

int				check_ft_isprint(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(isprint(i) == ft_isprint(i));
		i = i + 1;
	}
	printf("%s\n", "------isprint OK--------");
	return (1);

}

/*********is_ascii**********/

int				check_ft_isascii(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(isascii(i) == ft_isascii(i));
		i = i + 1;
	}
	printf("%s\n", "------isascii OK--------");
	return (1);
}

/*********is_anlnum**********/

int				check_ft_isalnum(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(isalnum(i) == ft_isalnum(i));
		i = i + 1;
	}
	printf("%s\n", "------isalnum OK--------");
	return (1);
}

/*********is_adigit**********/

int				check_ft_isdigit(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(isdigit(i) == ft_isdigit(i));
		i = i + 1;
	}
	printf("%s\n", "------isdigit OK--------");
	return (1);
}


/*********is_lower*********/

int				check_ft_islower(void)
{
	int			i;

	i = 0;
	while (i < 300)
	{
		assert(islower(i) == ft_islower(i));
		i = i + 1;
	}
	printf("%s\n", "------islower OK--------");
	return (1);
}

/*********is_upper**********/

int				check_ft_isupper(void)
{
	int			i;

	i = 0;
	while (i < 300)
	{
		assert(isupper(i) == ft_isupper(i));
		i = i + 1;
	}
	printf("%s\n", "------isupper OK--------");
	return (1);
}


/*********is_alpha**********/

int				check_ft_isalpha(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		assert(isalpha(i) == ft_isalpha(i));
		i = i + 1;
	}
	printf("%s\n", "------isalpha OK--------");
	return (1);
}

/****strcat***/
static int				check_ft_strcat(void)
{
	char		dest[50] = {0};
	char *a;
	char *b;

	if ((a = strcat(dest, "hello ")) != (b = ft_strcat(dest, "hello ")))
		printf("%p, %p\n", a, b);
	strcat(dest, "hello ");
/*	printf("%p, %s\n", dest, dest); */
	ft_strcat(dest, "salut ");
/*	printf("%p, %s\n", dest, dest); */
	printf("%s\n", "------strcat OK--------");
	return (1);
}

/*******FT_BZERO**************/

static void simple_string(void)
{
	char	control[10];
	char	subject[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);
	assert(memcmp(control, subject, 10) == 0);
	subject[0] = 'a';
	ft_bzero(subject, 0);
	assert(subject[0] == 'a');
}

static void test_only_bzero_first_x_chars(void)
{
	char	control[] = "123456789";
	char	subject[] = "123456789";

	bzero(control, 3);
	ft_bzero(subject, 3);
	assert(memcmp(subject, control, 10) == 0);
}

static void test_zero_case()
{
	char	control[] = "123456789";
	char	subject[] = "123456789";

	bzero(control, 0);
	ft_bzero(subject, 0);
	assert(memcmp(subject, control, 10) == 0);
}

void	check_ft_bzero()
{
	simple_string();
	test_only_bzero_first_x_chars();
	test_zero_case();
	printf("\n%s\n", "/********* NORMAL FUNCTIONS **********/");
	printf("%s\n", "------Bzero OK--------");
}

/***************** BONUS ******************/

/*****putstr****/

static void	check_ft_putstr(void)
{
//	ft_putstr("loool\n");
//	ft_putstr("ca marche !!!\n");
//	ft_putstr("sans dec  !!!\n");
	//char lol[5] = "lol\n";
	ft_putstr("------putstr OK------\n");
}

/*****memcmp****/

static int	check_ft_memcmp(void)
{
    char            ctab[11], ctab2[11];
    int             itab[11], itab2[11];
    unsigned long   ltab[11], ltab2[11];
    size_t          i, j;

    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 11)
        {
            ctab[j] = (char)rand();
            ctab2[j] = (char)rand();
			itab[j] = rand();
			itab2[j] = rand();
            ltab[j] = (unsigned long)rand() * LONG;
			ltab2[j] = (unsigned long)rand() * LONG;
            j++;
        }
		assert (memcmp(ctab, ctab2, sizeof(ctab)) == ft_memcmp(ctab, ctab2, sizeof(ctab)));
        memcpy(ctab2, ctab, sizeof(ctab));
		assert(memcmp(ctab, ctab2, sizeof(ctab)) == ft_memcmp(ctab, ctab2, sizeof(ctab)));
		assert(memcmp(itab, itab2, sizeof(itab)) == ft_memcmp(itab, itab2, sizeof(itab)));

		memcpy(itab2, itab, sizeof(itab));
        assert(memcmp(itab, itab2, sizeof(itab)) == ft_memcmp(itab, itab2, sizeof(itab)));

		assert(memcmp(ltab, ltab2, sizeof(ltab)) == ft_memcmp(ltab, ltab2, sizeof(ltab)));

		memcpy(ltab2, ltab, sizeof(ltab));
        assert(memcmp(ltab, ltab2, sizeof(ltab)) == ft_memcmp(ltab, ltab2, sizeof(ltab)));

				++i;
    }
    printf("%s\n", "------check memcmp OK--------");
	return (1);
}

/*****putchar****/

static void	check_ft_putchar(void)
{
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('p');
	ft_putchar('u');
	ft_putchar('t');
	ft_putchar('c');
	ft_putchar('h');
	ft_putchar('a');
	ft_putchar('r');
	ft_putchar(' ');
	ft_putchar('O');
	ft_putchar('K');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('-');
	ft_putchar('\n');
}

/***** MAIN ****/

int		main(void)
{
	check_ft_bzero();
	check_ft_strcat();
	check_ft_isalpha();
	check_ft_isdigit();
	check_ft_isalnum();
	check_ft_isascii();
	check_ft_isprint();
	check_ft_toupper();
	check_ft_tolower();
	check_ft_puts();
	check_ft_strlen();
	check_ft_memset();
	check_ft_memcpy();
	check_ft_strdup();
	check_ft_cat();
	check_ft_memcmp();
	check_ft_isupper();
	check_ft_islower();
	check_ft_putchar();
	check_ft_putstr();
	return (0);
}
