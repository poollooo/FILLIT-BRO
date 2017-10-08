/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:30:41 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/06 16:57:58 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Verifie que les tetriminos ont une bonne shape general et retourne
** le nombre de blocks
*/

int		check_shape(char *str, int size)
{
	int i;

	i = 0;
	if ((size = 0 || (size != 20 && size != 21))
	|| (str[4] != '\n' && str[9] != '\n' && str[14] != '\n' && str[19] != '\n')
	|| (str[20] != '\0' && str[20] != '\n'))
		return (0);
	while (i < size)
	{
		if ((i != 4 && i != 9 && i != 14 && i != 19 && i != 20)
		&& str[i] != '#' && str[i] != '.')
			return(0);
		i++;
	}
	return(1)
}
//
// int		check_connections(char *str)
// {
// 	int connections;
//
// 	connections =0 ;
// 	while (str[i])
// 	{
// 		if(str[i] == '#')
// 		{
// 			if(str[i + 1] && str[i + 1] == '#')
// 				connections++;
// 			if(str[i - 1] && str[i - 1] == '#')
// 				connections++;
// 			if(str[i + 5] && str[i + 5] == '#')
// 				connections++;
// 			if(str[i - 5] && str[i - 5] == '#')
// 				connections++;
// 		}
// 		i++;
// 	}
// 	if (connections != 6 || connections != 8)
// 		return (0);
// }
