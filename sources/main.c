/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/25 23:24:30 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/
void print_tetris(char **tetris)
{
	int i;
	int j;


	j = 0;
	i = 0;

	while (tetris[i] != '\0')
	{
		printf("numero du block : %d \n", i);

		j = 0;
		while (j < 8)
			printf("%d ", tetris[i][j++]);
		printf("\n");

		i++;
	}
	printf("\n");
}

char	**initiate_map(int map_size)
{
	char **map;
	int i;
	int j;

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
	int tetris_nb;
	char **map;
	int i;
	char spot[2];
	int j;


	j = 0;
	i = 0;
	spot[0] = 0;
	spot[1] = 0;
	tetris_nb = check_all(av[1]);
	i = min_map_size(tetris_nb);

	tetris_nb = 0;
	if (ac != 2)
	{
		printf("usage: fillit input_file\n");
		return (1);
	}

	if (check_all(av[1]) == 0)
		return (0);

	map = initiate_map(i);
	print_map(initiate_map(i), i);
	print_tetris(coordinates(av[1], check_all(av[1])));
	solve(map, coordinates(av[1], check_all(av[1])), tetris_nb, spot, j);
	printf("I EST EGALE A : %d\n", i);
	return (0);
}
