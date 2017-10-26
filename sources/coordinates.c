/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 23:35:17 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/26 01:05:35 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	*create_coord(char *buf)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*tetris;

	tetris = (char *)ft_strnew((sizeof(char) * 9));
	l = 0;
	i = 0;
	j = 0;
	k = 0;
	while (buf[l] != '#')
		l++;
	while (buf[l])
	{
		if (buf[l] == '#')
		{
			tetris[k] = i;
			k++;
			tetris[k] = j;
			k++;
		}
		if (buf[l] == '\n' && buf[l - 1] != '\n')
		{
			j++;
			i = i - 5;
		}
		l++;
		i++;
	}
	tetris[++k] = '%';
	return (tetris);
}

char	**read_input(char *av, int block_nb)
{
	int		i;
	char	*buf;
	int		fd;
	char	**tetris;

	tetris = (char **)ft_strnew((sizeof(char *) * block_nb) + 1);
	i = 0;
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(av, O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{
		tetris[i] = create_coord(buf);
		i++;
	}
	tetris[i] = NULL;
	free(buf);
	return (tetris);
}

char	**coordinates(char *av, int block_nb)
{
	char **tetris;

	tetris = (char **)ft_strnew((sizeof(char *) * block_nb) + 1);
	if (tetris == NULL)
		return (0);
	tetris = read_input(av, block_nb);
	return (tetris);
}
