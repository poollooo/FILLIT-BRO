/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:02:34 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/18 16:32:43 by jostraye         ###   ########.fr       */
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

typedef struct t_tetris
	{
		int numero;
		int coord[4];
		struct t_tetris	*next;
	}			t_tetris;


/*
** Check_all file :
*/

	int		check_shape(char *str);
	int		check_connections(char *str);
	int		check_last(char *str);
	int 	check_all(char **av);
	int		*coordinates(char *av, int block_nb);
	int		find_min(int *map);
	int		*assign_spot(int *map, int *tet);
	int		ft_success(int *map, int *tet);
	int		*adjust_map(int *map, int *tetris);

	/*
	** Coordonnees file :
	*/

	int 			*create_coord(char *buf, int block_nb);
	t_tetris		*coordonnees(char *av);

	/*
	** Solve file :
	*/

	t_map solve(t_tetris tetris);



#endif
