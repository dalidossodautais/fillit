/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:15 by ddosso-d          #+#    #+#             */
/*   Updated: 2016/12/17 11:43:55 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	***ft_from_str_to_tab(char *s)
{
	char	***t;
	int		a;
	int		b;

	a = 0;
	while (s[a * 21])
		a++;
	t = (char ***)malloc(sizeof(char **) * (a + 1));
	t[a] = NULL;
	while (a--)
	{
		t[a] = (char **)malloc(sizeof(char *) * 5);
		b = -1;
		while (++b < 4)
			t[a][b] = (char *)malloc(sizeof(char) * 5);
		t[a][b] = NULL;
		b = -1;
		while (++b < 20)
		{
			t[a][b / 5][b % 5] = '\0';
			if (s[a * 21 + b] != '\n')
				t[a][b / 5][b % 5] = s[a * 21 + b];
		}
	}
	return (t);
}

void	ft_free_tab(char **s)
{
	int		a;

	a = 0;
	while (s[a])
		free(s[a++]);
	free(s);
}
