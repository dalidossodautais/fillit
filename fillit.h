/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:30:07 by ddosso-d          #+#    #+#             */
/*   Updated: 2016/12/17 15:32:45 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		ft_verif(char *s);

char	***ft_from_str_to_tab(char *s);

void	ft_test_lengths(char ***t);
void	ft_free_tab(char **s);

void	ft_putendl(char const *s);
void	ft_puttab(char **s);

#endif
