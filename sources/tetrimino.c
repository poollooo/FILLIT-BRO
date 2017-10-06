/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:30:41 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/06 11:47:10 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Verifie que les tetriminos ont une bonne shape general et retourne
** le nombre de blocks
*/

int		nbr_block(char *str)
{
	int i;
	int nb_block;

	i = 0;
	nb_block = 0;
	while (str[i])
	{
		if (((i + 1 - nb_block) % 5) == 0 && str[i] != '\n')
			return (0);
		if (((i + 1) % 21) == 0 && str[i] != '\n')
			return (0);
		if ((((i + 1 - nb_block) % 5) == 1 || ((i + 1 - nb_block) % 5) == 2 ||
		((i + 1 - nb_block) % 5) == 3 || ((i + 1 - nb_block) % 5) == 4)
		&& str[i] == '\n')
			return (0);
		if (((i + 1) % 21) == 0 && str[i] == '\n')
			nb_block++;
		i++;
	}
	return (nb_block + 1);
}

int		check_form(char *str, int size)
{
	int i;
	int block;

	i = 0;
	block = 0;
	if (size = 0)
		return (0);
	if (size != 20 && size != 21)
		return (1);
	while (i < size)
	{
		if (str[i] == '#')
			block++;
		else if (str[i] != '#' || str[i] != '.' || str[i] != '\n')
			return (2);
		i++;
	}
	if (str[4] != '\n' && str[9] != '\n' && str[14] != '\n' && str[19] != '\n')
		return (3);
	if (block != 4)
		return (4);
	if (str[20] && str[20] != '\n')
		return (5);
}

int		check_connections(char *str)
{
	int connections;

	connections =0 ;
	while (str[i])
	{
		if(str[i] == '#')
		{
			if(str[i + 1] && str[i + 1] == '#')
				connections++;
			if(str[i - 1] && str[i - 1] == '#')
				connections++;
			if(str[i + 5] && str[i + 5] == '#')
				connections++;
			if(str[i - 5] && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections != 6 || connections != 8)
		return (0);
}
