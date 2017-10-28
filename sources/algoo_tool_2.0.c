/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoo_tool_2.0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 00:59:05 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/27 18:00:09 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	*reset_spot(void)
{
	static char spot[2];

	spot[0] = 0;
	spot[1] = 0;
	return (spot);
}

int		fml(char **map)
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
