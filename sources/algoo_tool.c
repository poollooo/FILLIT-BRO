/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoo_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:42:50 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/25 23:12:12 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char *reset_spot()
{
	static char spot[2];


	spot[0] = 0;
	spot [1] = 0;
	return (spot);
}

int		find_max_letter(char **map)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] > max)
				max = map[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

char *find_first_spot(char **map, int max_letter)
{
	int j;
	int i;
	static char spot[2];

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != (char)max_letter && map[j][i])
			i++;
		if (map[j][i] == max_letter)
			break;
		j++;
	}
	spot[0] = i;
	spot[1] = j;
	return (spot);
}
int count_dots(char **map)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}
char	**free_map(char **map, int max_letter)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == max_letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int min_map_size(int tetris_nb)
{
	int i;

	i = 0;
	if (tetris_nb == 1)
		return (i = 2);
	if (tetris_nb == 2)
		return (i = 3);
	if (tetris_nb == 3 || tetris_nb == 4)
		return (i = 4);
	if (tetris_nb == 5 || tetris_nb == 6)
		return (i = 5);
	if (tetris_nb >= 7 && tetris_nb <= 9)
		return (i = 6);
	if (tetris_nb >= 10 && tetris_nb <= 12)
		return (i = 7);
	if (tetris_nb >= 13 && tetris_nb <= 16)
		return (i = 8);
	if (tetris_nb >= 17 && tetris_nb <= 20)
		return (i = 9);
	if (tetris_nb >= 21 && tetris_nb <= 25)
		return (i = 10);
	if (tetris_nb >= 26)
		return (i = 11);
	else
		return (0);
}

char **fill_map(char **map, char **tetris, int tr_n, char *spot)
{
	int i;

	i = 0;
	while (i < 8)
	{
		map[tetris[tr_n][i + 1] + spot[1]][tetris[tr_n][i] + spot[0]] = tr_n + 'A';
		i = i + 2;
	}
	return (map);
}
