/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:27:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/25 16:15:12 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	print_map(char **map, int map_s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map_s)
	{
		while (i < map_s)
		{
			printf("%c ", map[j][i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

char *next_spot(char *spot, int map_s)
{
	static char	next_spot[3];
	int			i;
	int			j;
	int			k;

	i = spot[0];
	j = spot[1];
	if (j == map_s - 1)
	{
		k = i;
		i = j;
		j = k + 1;
	}
	else if (i == 0)
	{
		i = j + 1;
		j = 0;
	}
	else
	{
		i--;
		j++;
	}

	next_spot[0] = i;
	next_spot[1] = j;
	next_spot[2] = '\0';
	return (next_spot);
}

int size(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char *success(char **map, char **tr, int tr_n, char *spot)
{
	/* verifier que ca rentre */
	int i;
	int map_s;

	printf("SUCCESS \n");
	map_s = size(map);
	while (spot[1] != map_s && spot[0] != map_s)
	{
		printf("\nCurrent spot : %d:%d \n", spot[0], spot[1]);
		printf("tr NUMBER %d \n\n", tr_n);

		i = 0;
		while (i < 8)
		{
			if (tr[tr_n][i] + spot[0] < 0 || tr[tr_n][i] + spot[0] == map_s
		|| tr[tr_n][i + 1] + spot[1] < 0 || tr[tr_n][i + 1] + spot[1] == map_s
	|| map[tr[tr_n][i + 1] + spot[1]][tr[tr_n][i] + spot[0]] != '.')
				{
					printf("////ce morceau marche pas\\\\\\\\ \n");
					break;
				}
			i = i + 2;
			printf("morceau %d: ok \n", i / 2);
			printf("tr %d:%d \n\n", tr[tr_n][i - 2], tr[tr_n][i - 1]);

		}
		if (i == 8)
		{
			printf("////It's a success for tetris %d\\\\\\\\ \n\n",tr_n);
			return (spot);
		}
		spot = next_spot(spot, map_s);

	}
	printf("\n SUCCESS FIN \n");
	return (spot);
}

char *find_spot(char **map, int tr_n)
{
	int i;
	int j;
	static char spot[3];

	i = 0;
	j = 0;
	while (map[j] && j < size(map))
	{
		i = 0;
		while (map[j][i] != (tr_n + 'A')  && i < size(map))
			i++;
		j++;
	}
	j--;
	if (i == size(map))
		i = 0;
	if (j == size(map))
		j = 0;
	spot[0] = i;
	spot[1] = j;
	printf("\n FIND SPOT RESULT : %d %d \n", spot[0], spot[1]);

	return (spot);
}

char	**solve(char **map, char **tetris, 	int tr_n, char *spot)
{
	printf("\n *****SOLVE***** \n");

	int map_s;
	int i;
	i = 0;
	map_s = size(map);
	spot = success(map, tetris, tr_n, spot);
	printf("---- TETRIS NUMBER ---- %d \n", tr_n);
	printf("\n ***spot to print*** : %d %d \n", spot[0], spot[1]);

	if ((spot[0] == map_s || spot[1] == map_s) && tr_n == 0)
	{
		printf("HELLO FRANKY////////////////////////////");
		spot[0] = 0;
		spot[1] = 0;
		map_s++;
		tr_n = 0;
		printf("---- TETRIS NUMBER ---- %d \n", tr_n);
		printf("map_s set to %d \n", map_s);
		map = initiate_map(map_s);
		printf("Max letter == %d\n", find_max_letter(map));


	}
	else if ((spot[0] == map_s || spot[1] == map_s) && tr_n > 0)
	{
		tr_n--;
		spot = next_spot(find_spot(map, tr_n), tr_n);
		printf("\n ***spot to print*** : %d %d \n", spot[0], spot[1]);
		map = initiate_map(map_s);
		printf("Max letter == %d\n", find_max_letter(map));

	}

	else
	{
		i = 0;
		printf("\n spot to print : %d %d \n", spot[0], spot[1]);
		map = fill_map(map, tetris, tr_n, spot);
		tr_n++;

		printf("Max letter == %d\n", find_max_letter(map));
		spot[0] = 0;
		spot[1] = 0;
	}

	print_map(map, map_s);
	printf(" FREED MAP \n");
	// map = free_map(map, find_max_letter(map));
	// print_map(map, map_s);

	printf("END OF SOLVE - GO TETRIS %d \n\n", tr_n);

	if (tetris[tr_n] == NULL)
		return (map);
	solve(map, tetris, tr_n, spot, previous_tr_n);
	return (map);
}
