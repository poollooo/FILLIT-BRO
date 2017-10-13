/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonnees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:55 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/12 16:52:38 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** ce document permet d'extraire du fichier input l'information necessaire pour
faire tourner le programme
*/

int *create_coord(char *buf)
{
	int i;
	int j;
	int k;
	static int coord_1[4];

	i = 0;
	j = 0;
	k = 0;
	while (buf[i] == '.')
		i++;
	coord_1[k] = j;
	while (buf[i])
	{
		i++;
		if (buf[i] == '\n')
			j = j + 15 - 4;
		j++;
		if (buf[i] == '#')
		{
			coord_1[++k] = j;
		}

	}
	return (coord_1);
}

t_tetri		*coordonnees(char *av)
{
	int 	i;
	int		tetri_num;
	char	*buf;
	int		fd;
	t_tetri	*tetris;

	tetri_num = 0;
	i = 0;
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(av, O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{
		tetri_num++;
		tetris->numero = tetri_num;
		// while (i++ < 4)
			// tetris->coord[i] = create_coord(buf)[i];
		tetris = tetris->next_tetri;
	}
	tetris->next_tetri = NULL;
	free(buf);
	return (tetris);
}


int		main(int ac, char **av)
{
	int i;
	i = 0;

	if (check_all(ac, av) == 1)
		while (coordonnees(av[1])->coord[i++])
		printf("La map est :\n %d", coordonnees(av[1])->coord[i]);
	return (0);
}
