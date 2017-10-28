/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/27 18:07:03 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

char	**initiate_map(int map_size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **)ft_strnew(sizeof(char *) * map_size + 1);
	while (j < map_size)
	{
		map[j] = ft_strnew(sizeof(char) * map_size + 1);
		while (i < map_size)
		{
			map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int		main(int ac, char **av)
{
	int		tetris_nb;
	char	**map;
	int		i;
	char	spot[2];

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (check_all(av[1]) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	i = 0;
	spot[0] = 0;
	spot[1] = 0;
	tetris_nb = check_all(av[1]);
	i = min_map_size(tetris_nb);
	tetris_nb = 0;
	map = initiate_map(i);
	solve(map, coordinates(av[1], check_all(av[1])), tetris_nb, spot);
	return (0);
}
