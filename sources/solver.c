/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:53:13 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/27 18:15:58 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	**print_map(char **map, int map_s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map_s)
	{
		ft_putstr(map[j]);
		j++;
		ft_putstr("\n");
	}
	ft_putstr("\n");
	return (map);
}

char	*next_spot(char *spot, int map_s)
{
	if (spot[0] < map_s)
		spot[0]++;
	if (spot[0] == map_s)
	{
		spot[0] = 0;
		spot[1]++;
	}
	return (spot);
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

char	**solve(char **mp, char **tetris, int tr_n, char *spot)
{
	if (tetris[tr_n] == NULL)
		return (print_map(mp, size(mp)));
	spot = success(mp, tetris, tr_n, spot);
	if ((spot[0] == size(mp) || spot[1] == size(mp))
	&& (fml(mp) == '.' || cd(mp) < 4))
	{
		mp = initiate_map(size(mp) + 1);
		spot = reset_spot();
		tr_n = 0;
	}
	else if ((spot[0] == size(mp) || spot[1] == size(mp)) && fml(mp) != '.')
	{
		tr_n = fml(mp) - 65;
		spot = find_first_spot(mp, fml(mp));
		spot = next_spot(spot, size(mp));
		mp = free_map(mp, fml(mp));
	}
	else
	{
		mp = fill_map(mp, tetris, tr_n, spot);
		spot = reset_spot();
		tr_n++;
	}
	solve(mp, tetris, tr_n, spot);
	return (mp);
}
