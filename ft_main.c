/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:30:40 by ddosso-d          #+#    #+#             */
/*   Updated: 2016/12/18 11:44:28 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	char	tmp[546];
	char	*s;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("usage:	./fillit tetrommino_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0 || read(fd, tmp, 546) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	s = tmp;
	close(fd);
	if (ft_verif(s))
		ft_test_lengths(ft_from_str_to_tab(s));
	else
		ft_putendl("error");
	return (0);
}
