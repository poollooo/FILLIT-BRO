/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoo_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:42:50 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/25 15:37:48 by jostraye         ###   ########.fr       */
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
