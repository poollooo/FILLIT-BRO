/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 23:35:17 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/27 13:36:35 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		skip_dot(char *buf)
{
	int l;

	l = 0;
	while (buf[l] != '#')
		l++;
	return (l);
}

char	*create_coord(char *buf)
{
	int		i[4];
	char	*tetris;

	tetris = (char *)ft_strnew((sizeof(char) * 9));
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	i[0] = skip_dot(buf);
	while (buf[i[0]])
	{
		if (buf[i[0]] == '#')
		{
			tetris[i[3]++] = i[1];
			tetris[i[3]++] = i[2];
		}
		if (buf[i[0]] == '\n' && buf[i[0] - 1] != '\n')
		{
			i[2]++;
			i[1] = i[1] - 5;
		}
		i[0]++;
		i[1]++;
	}
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
