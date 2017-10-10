/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:55 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/10 12:36:47 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ce document permet d'extraire du fichier input l'information necessaire pour
faire tourner le programme
*/

t_tetri		coordinator(void)
{
	int i;
	char *buf;
	char *av;
	int fd;

	i = 0;
	*av = NULL;
	buf = (char *)malloc(22);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{

		i++;
	}
}
