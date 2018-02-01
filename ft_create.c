/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:30:26 by ddosso-d          #+#    #+#             */
/*   Updated: 2016/12/16 19:00:00 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static char	**ft_create_empty(int l)
{
	char	**s;
	int		a;

	s = (char **)malloc(sizeof(s) * (l + 1));
	s[l] = NULL;
	a = -1;
	while (++a < l)
	{
		s[a] = (char *)malloc(sizeof(s[a]) * (l + 1));
		s[a][l] = '\0';
	}
	a = -1;
	while (++a < l * l)
		s[a / l][a % l] = '.';
	return (s);
}

static char	**ft_create_copy(int l, char **s)
{
	char	**v;
	int		a;

	v = (char **)malloc(sizeof(v) * (l + 1));
	v[l] = NULL;
	a = -1;
	while (++a < l)
	{
		v[a] = (char *)malloc(sizeof(v[a]) * (l + 1));
		v[a][l] = '\0';
	}
	a = -1;
	while (++a < l * l)
		v[a / l][a % l] = s[a / l][a % l];
	return (v);
}

static int	ft_enter(char **s, char **u, int a, int l)
{
	int		b;

	b = -1;
	while (++b < 16)
	{
		if (u[b / 4][b % 4] == '#')
		{
			if (!(a / l + b / 4 < l) || !(a % l + b % 4 < l) ||
				s[a / l + b / 4][a % l + b % 4] != '.')
			{
				return (0);
			}
		}
	}
	return (1);
}

static int	ft_possible_or_not(char ***s, char ***t, int c, int l)
{
	int		a;
	int		b;
	char	**v;

	a = -1;
	while (++a < l * l - 3)
	{
		if (ft_enter(*s, t[c], a, l))
		{
			v = ft_create_copy(l, *s);
			b = -1;
			while (++b < 16)
				if (t[c][b / 4][b % 4] == '#')
					(*s)[a / l + b / 4][a % l + b % 4] = c + 'A';
			if (!t[c + 1])
				ft_puttab(*s);
			if (!t[c + 1])
				return (1);
			else if (ft_possible_or_not(s, t, c + 1, l))
				return (1);
			ft_free_tab(*s);
			*s = v;
		}
	}
	return (0);
}

void		ft_test_lengths(char ***t)
{
	int		l;
	int		i;
	char	**p;

	l = 2;
	i = 0;
	while (!i)
	{
		p = ft_create_empty(l);
		i = ft_possible_or_not((&p), t, 0, l);
		ft_free_tab(p);
		l++;
	}
	l = 0;
	while (t[l])
		ft_free_tab(t[l++]);
	free(t);
}
