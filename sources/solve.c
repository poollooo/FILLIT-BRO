/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:27:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 14:44:56 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

backtrack()

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

	if (tetri->next_tetri == NULL)
		return(t_map);
	else
	{
		if(success)
		{
			tetri = tetri->next_tetri;
			
		}
	}
}
