# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 11:33:49 by ddosso-d          #+#    #+#              #
#    Updated: 2016/12/18 11:43:01 by gricquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit
FLAGS = -Wall -Wextra -Werror
SRCS =	ft_verif.c ft_transform.c ft_create.c ft_print.c ft_main.c
OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
