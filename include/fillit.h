/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:02:34 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 15:25:22 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct t_map
	{
		int map_distance[196];
		char map_letters[196];
	}			t_map;

typedef struct t_tetri
	{
		int numero;
		int coord[4];
		struct t_tetri	*next_tetri;
	}			t_tetri;


/*
** Check_all file :
*/
	int		check_shape(char *str);
	int		check_connections(char *str);
	int		check_last(char *str);
	int 	check_all(int ac, char **av);

	/*
	** Coordonnees file :
	*/

	int 			*create_coord(char *tetri_piece);
	t_tetri		coordonnees(char *av);

	/*
	** Solve file :
	*/

	t_map solve(t_tetri tetri);



#endif
