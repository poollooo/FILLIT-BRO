/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:53:13 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/26 01:06:50 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	print_map(char **map, int map_s)
{
	int		i;
	int		j;

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
	printf("\n");
}

char	*next_spot(char *spot, int map_s)
{
	static char	next_spot[2];
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
	return (next_spot);
}

int		size(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	*success(char **map, char **tr, int tr_n, char *spot)
{
	int i;
	int map_s;

	map_s = size(map);
	while (spot[1] != map_s && spot[0] != map_s)
	{
		i = 0;
		while (i < 8)
		{
			if (tr[tr_n][i] + spot[0] < 0 || tr[tr_n][i] + spot[0] >= map_s
		|| tr[tr_n][i + 1] + spot[1] < 0 || tr[tr_n][i + 1] + spot[1] >= map_s
	|| map[tr[tr_n][i + 1] + spot[1]][tr[tr_n][i] + spot[0]] != '.')
			{
				break ;
			}
			i = i + 2;
		}
		if (i == 8)
			return (spot);
		spot = next_spot(spot, map_s);
	}
	return (spot);
}

char	**solve(char **map, char **tetris, int tr_n, char *spot, int j)
{
	int		map_s;
	int		i;
	int		max_letter;

	if (tetris[tr_n] == NULL)
		return (map);
	i = 0;
	map_s = size(map);
	printf("map size %d \n", map_s);
	j++;
	printf("ceci est j %d \n", j);
	spot = success(map, tetris, tr_n, spot);
	max_letter = find_max_letter(map);
	if ((spot[0] == map_s || spot[1] == map_s))
	{
		if (max_letter == '.' || count_dots(map) < 4)
		{
			map_s++;
			map = initiate_map(map_s);
			spot = reset_spot();
			tr_n = 0;
		}
		else if (max_letter != '.')
		{
			tr_n = max_letter - 65;
			spot = find_first_spot(map, max_letter);
			spot = next_spot(spot, map_s);
			map = free_map(map, max_letter);
		}
	}
	else
	{
		map = fill_map(map, tetris, tr_n, spot);
		spot = reset_spot();
		tr_n++;
	}
	print_map(map, map_s);
	if (tetris[tr_n] != NULL)
		solve(map, tetris, tr_n, spot, j);
	return (map);
}
