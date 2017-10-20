/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:27:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/20 12:18:45 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"


int ft_success(int *map, int *tetris)
{
	int i;

	i = 0;
	tetris = assign_spot(map, tetris);
	while (i++ < 4)
		if (map[tetris[i + map [198] * 4] + 1] > 60)
			return (0);
	return (1);
}

int *assign_spot(int *map, int *tet)
{
	tet[(map[198]) * 4] = map[199] + tet[(map[198]) * 4] ;
	printf(" %d - ", tet[(map[198]) * 4]);
	tet[(map[198]) * 4 + 1] = map[199] + tet[(map[198]) * 4 + 1] ;
	printf(" %d -", tet[(map[198]) * 4 + 1]);
	tet[(map[198]) * 4 + 2] = map[199] + tet[(map[198]) * 4 + 2] ;
	printf(" %d - ", tet[(map[198]) * 4 + 2]);
	tet[(map[198]) * 4 + 3] = map[199] + tet[(map[198]) * 4 + 3] ;

	printf(" %d \n", tet[(map[198]) * 4 + 3]);

	return (tet);
}

int find_min(int *map)
{
	int i;
	int j;
	int min;

	j = 1;
	min = 50;
	i = 1;
	while (i < 196)
	{
		if (min > map[i] && i % 14 <= map[197] && i / 14 < map[197])
		{
			min = map[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int *solver(int *map, int *tetris)
{
	int i;
	int success;

	i = 0;

	/* condition d'arret */
	if(tetris[map[198] * 4] == -1)
		return (map);

	success = ft_success(map, tetris);
	/* cette fonction ecrit le resultat approprie, une lettre si le tetris
	rentre, un 99 si l'endroit n'est pas adapte pour le tetris*/
	if (success == 0)
	{
		map[map[199] + 1] = 40;
		map[199] = find_min(map);
		// printf("ola %d \n", map[198]);
		solver(map, tetris);
	}
	if (success == 1)
	{
		map[1 + assign_spot(map, tetris)[map[198] * 4]] = map[198] + 'A';
		// map[1 + assign_spot(map, tetris)[map[198] * 4 + 1]] = map[198] + 'A';
		// map[1 + assign_spot(map, tetris)[map[198] * 4 + 2]] = map[198] + 'A';
		// map[1 + assign_spot(map, tetris)[map[198] * 4 + 3]] = map[198] + 'A';
		printf("ici %d \n", (1 + assign_spot(map, tetris)[map[198] * 4 + 1]));

		map[198] = map[198] + 1;
		map[199] = find_min(map);

		solver(map, tetris);

	}
	return(map);
}

int *initiate_map()
{
	int i;
	int j;
	static int map[201];

	map[0] = 100;
	i = 0;
	j = 0;
	while (i < 196)
	{
		if (i != 0 && i % 14 == 0)
		{
			map[i] = 100;
			i++;
			j++;
		}
		map[i] = i % 14 + j - 2;
		i++;
	}
	map[196] = 100;

	/* l'index smallest map est a 197 */
	map[197] = 100;

	/* l'index bck_nb est a 198 */
	map[198] = 0;

	/* l'index min est a 199 */
	map[199] = 0;
	return (map);
}


int		main(int ac, char **av)
{
	int i;
	int map[201];
	static int *tetris;

	if (ac != 2)
	{
		printf("usage: fillit input_file\n");
		return (1);
	}
	i = 0;
	while (i++ < 201)
		map[i] = initiate_map()[i];
	map[198] = check_all(av);
	tetris = coordinates(av[1], map[198]);

	i = 0;
	map[198] = 0;
	while (i++ < 201)
		map[i] = solver(map, tetris)[i];
	i = 0;

	while (i++ < 196)
	{
		if (i % 14 <= map[197] && (i / 14) < map[197])
			printf("	%d",map[i]);
		if (i % 14 == 0)
			printf ("\n");
	}
	printf("min : %d \n",find_min(map));
	// i = ft_success(map, tetris);
	// printf("success : %d \n", i);
	return (0);
}



/* debut de l'algorithme */
/*
idea: the first tetris is taken, compared to the map until it fits somwhere
(closest as possible to the point of origin)
when a fit is found, the tetris is written down on the map, than the same process
is done again with the next tetris.
if it appears that no fit can be found the algorithm backtracks to the last ok
tetris and changes its position
*/
