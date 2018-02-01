/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:31 by ddosso-d          #+#    #+#             */
/*   Updated: 2016/12/13 11:31:33 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_valid_file(char *s)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (a <= 19)
	{
		if ((a == 4 || a == 9 || a == 14 || a == 19) && s[a] != '\n')
			return (0);
		else
		{
			if (s[a] != '.' && s[a] != '#' && s[a] != '\n')
				return (0);
			else if (s[a] == '#')
				b++;
		}
		a++;
	}
	if (b != 4)
		return (0);
	return (1);
}

static char	*ft_to_the_top(char *s)
{
	size_t	a;

	while (s[0] == '.' && s[1] == '.' && s[2] == '.' && s[3] == '.')
	{
		a = 0;
		while (a < 15)
		{
			s[a] = s[a + 5];
			a++;
		}
		while (a < 19)
		{
			s[a] = '.';
			a++;
		}
	}
	return (s);
}

static char	*ft_to_the_left(char *s)
{
	size_t	a;

	while (s[0] == '.' && s[5] == '.' && s[10] == '.' && s[15] == '.')
	{
		a = 0;
		while (a < 4)
		{
			s[a * 5] = s[a * 5 + 1];
			s[a * 5 + 1] = s[a * 5 + 2];
			s[a * 5 + 2] = s[a * 5 + 3];
			s[a * 5 + 3] = '.';
			a++;
		}
	}
	return (s);
}

static int	ft_exist_or_not(char *s)
{
	if ((s[0] == '#' && s[1] == '#' && s[2] == '#' && s[3] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[2] == '#' && s[7] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[6] == '#' && s[11] == '#') ||
		(s[0] == '#' && s[5] == '#' && s[10] == '#' && s[15] == '#') ||
		(s[0] == '#' && s[5] == '#' && s[10] == '#' && s[11] == '#') ||
		(s[0] == '#' && s[5] == '#' && s[6] == '#' && s[7] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[2] == '#' && s[5] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[5] == '#' && s[10] == '#') ||
		(s[1] == '#' && s[6] == '#' && s[10] == '#' && s[11] == '#') ||
		(s[2] == '#' && s[5] == '#' && s[6] == '#' && s[7] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[5] == '#' && s[6] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[6] == '#' && s[7] == '#') ||
		(s[1] == '#' && s[2] == '#' && s[5] == '#' && s[6] == '#') ||
		(s[0] == '#' && s[5] == '#' && s[6] == '#' && s[11] == '#') ||
		(s[1] == '#' && s[5] == '#' && s[6] == '#' && s[10] == '#') ||
		(s[0] == '#' && s[1] == '#' && s[2] == '#' && s[6] == '#') ||
		(s[1] == '#' && s[5] == '#' && s[6] == '#' && s[7] == '#') ||
		(s[0] == '#' && s[5] == '#' && s[6] == '#' && s[10] == '#') ||
		(s[1] == '#' && s[5] == '#' && s[6] == '#' && s[11] == '#'))
		return (1);
	return (0);
}

int			ft_verif(char *s)
{
	size_t	a;

	a = 0;
	while (s[a * 21])
	{
		if (!ft_valid_file(s + a * 21))
			return (0);
		ft_to_the_top(s + a * 21);
		ft_to_the_left(s + a * 21);
		if (!ft_exist_or_not(s + a * 21))
			return (0);
		a++;
	}
	if (s[a * 21 - 1])
		return (0);
	return (1);
}