/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:53:13 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/25 16:25:24 by jostraye         ###   ########.fr       */
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

char	**solve(char **map, char **tetris, 	int tr_n, char *spot)
{
	printf("\n *****SOLVE***** \n");

	int map_s;
	int i;
	int max_letter;
	i = 0;
	map_s = size(map);
	spot = success(map, tetris, tr_n, spot);
	printf(" TETRIS NUMBER  %d \n", tr_n);
	printf("\n ************ spot out of success function ************ : %d %d \n\n", spot[0], spot[1]);

	if ((spot[0] == map_s || spot[1] == map_s))
	{
		max_letter = find_max_letter(map);
		printf("max letter %d \n", find_max_letter(map));
		printf("success spot bigger than map \n");
		if (max_letter == '.')
		{
			printf("no tetris on map \n");
			map_s++;
			map = initiate_map(map_s);
			spot = reset_spot();
			tr_n = 0;
		}
		else if (max_letter != '.')
		{

			tr_n = max_letter - 65;
			printf("tetris %d deleted from map \n", tr_n);
			spot = find_first_spot(map, max_letter);
			printf("\n first spot of the letter : %d %d \n", spot[0], spot[1]);
			spot = next_spot(spot, map_s);
			printf("\n ***next spot to print*** : %d %d \n", spot[0], spot[1]);
			map = free_map(map, max_letter);
		}
	}
	else
	{
		printf("tetris %d written on map \n", tr_n);
		map = fill_map(map, tetris, tr_n, spot);
		spot = reset_spot();
		tr_n++;
	}
	print_map(map, map_s);

	printf("checking if tetris %d is the last \n", tr_n);
	if (tetris[tr_n] == NULL)
		return (map);
	printf("solving tetris %d \n", tr_n);
	if (tetris[tr_n] != NULL)
		solve(map, tetris, tr_n, spot);
	return (map);
}
