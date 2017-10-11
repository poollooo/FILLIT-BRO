/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonnees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:55 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 14:18:50 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ce document permet d'extraire du fichier input l'information necessaire pour
faire tourner le programme
*/

int *create_coord(char *tetri_piece)
{
	int i;
	int j;
	int *coord[4];

	i = 0; //il amene le buffer au premier #
	j = 0; // il compte a partir du premier  pou rdonner la position de chaque #
	while(buf[i] == '.')
		i++;
	coord[0] = j;
	while(buf[i])
	{
		i++;
		j++;
		if (buf[i] == '#')
		{
			++coord = j;
		}
		if (buf[i] == '\n')
			j = j + 15 - 4;
	}
	return(coord);
}

t_tetri		coordonnees(char *av)
{
	int		tetri_num;
	char	*buf;
	int		fd;
	t_tetri	tetris;

	tetri_num = 0;
	i = 0;
	buf = (char *)malloc(22);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{
		tetri_num++;
		tetris->numero = tetri_num;
		tetris->coord = create_coord(buf);
		tetris = tetris->next_tetri;
	}
	tetris->next_tetri == NULL;
	return(t_tetri);
}
