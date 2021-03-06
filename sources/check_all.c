/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:30:41 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/27 18:09:33 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Verifie que les tetriminos ont une bonne shape general et verifie
** s'il y a bien 4 '#' et 12 "."
*/

int		check_shape(char *str)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		if (str[i] == '.')
			k++;
		i++;
	}
	if ((str[4] != '\n' || str[9] != '\n'
	|| str[14] != '\n' || str[19] != '\n'))
		return (0);
	if (j != 4 || k != 12)
		return (0);
	else
		return (1);
}

int		check_connections(char *str)
{
	int i;
	int connections;

	i = 0;
	connections = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] && str[i + 1] == '#')
				connections++;
			if (str[i - 1] && str[i - 1] == '#')
				connections++;
			if (str[i + 5] && str[i + 5] == '#')
				connections++;
			if (str[i - 5] && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	else
		return (0);
}

int		check_last(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n' && (str[i - 2] == '.' || str[i - 2] == '#'))
		return (1);
	else
		return (0);
}

/*
** Change the main in a runable function to use in our Main.c
*/

int		check_all(char *av)
{
	int		fd;
	char	*buf;
	char	*str;
	int		block_nb;
	int		rea;

	block_nb = 0;
	buf = (char *)malloc(22);
	fd = open(av, O_RDONLY);
	while ((rea = read(fd, buf, 21)) != 0)
	{
		if (rea != 21 && rea != 20)
			return (0);
		if (check_shape(buf) == 0)
			return (0);
		if (check_connections(buf) == 0)
			return (0);
		block_nb++;
	}
	fd = open(av, O_RDONLY);
	str = (char *)malloc(22 * block_nb);
	read(fd, str, 21 * block_nb);
	if (check_last(str) == 0)
		return (0);
	return (block_nb);
}
