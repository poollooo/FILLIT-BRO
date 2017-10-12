/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonnees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:55 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 23:02:56 by pnizet           ###   ########.fr       */
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
		j++;
		if (buf[i] == '#')
		{
			coord_1[++k] = j;
		}
		if (buf[i] == '\n')
			j = j + 15 - 4;
	}
	return (coord_1);
}

int	*ft_intdup(const int *s1)
{
	int	*s2;

	s2 = (int*)malloc(sizeof(int) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	else
		return (ft_strcpy(s2, s1));
}


t_tetri		coordonnees(char *av)
{
	int i;
	int		tetri_num;
	char	*buf;
	int		fd;
	t_tetri	*tetris;

	tetri_num = 0;
	i = 0;
	buf = (char *)malloc(22);
	fd = open(av, O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{
		tetri_num++;
		tetris->numero = tetri_num;
		tetris->coord = ft_intdup(create_coord(buf));
		tetris = tetris->next_tetri;
	}
	tetris->next_tetri == NULL;
	return (t_tetri);
}


int		main(int ac, char **av)
{
	if (check_all(int ac, char **av) == 3)
		printf("La map est :\n %s", coordonnees(av[1]));
	return (0);
}
