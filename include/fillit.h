/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:02:34 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 14:17:20 by jostraye         ###   ########.fr       */
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

	int		check_shape(char *str);
	int		check_connections(char *str);
	int		check_last(char *str);

	t_tetri		coordinator(void);


#endif
