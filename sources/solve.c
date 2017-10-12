/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:27:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 22:24:43 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map backtrack(t_map map, t_tetri tetri)
{
	int success;

	success = 0;
	if (tetri->next_tetri == NULL)
		return(t_map);
	else
	{
		if (success)
		{
			tetri = tetri->next_tetri;
			if (check_position(t_map, t_tetri))
			{
				write_map(t_map, t_tetri);
				success = 1;
			}
			if (!check_position(t_map, t_tetri))
			{
				success = 0;
				break;
			}
			backtrack(map, tetri);
		}
		else
			backtrack(map, tetri);
	}
}

t_map solve(t_tetri tetri)
{
	int i;
	t_map map;

/* initialisation de la map */
	i = 0;
	while (i < 196)
	{
		map->map_distance[i] = i % 14;
		map->map_letters[i] = '.';
	}

/* debut de l'algorithme */
/*
idea: the first tetri is taken, compared to the map until it fits somwhere
(closest as possible to the point of origin)
when a fit is found, the tetri is written down on the map, than the same process
is done again with the next tetri.
is it appears that no fit can be found the algorithm backtracks to the last ok
tetri and changes its position
*/
	return (backtrack(map, tetri));

}
Add Comment
