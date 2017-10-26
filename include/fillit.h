/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:02:34 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/25 22:59:05 by jostraye         ###   ########.fr       */
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

/*
** Check_all file :
*/

	int		check_shape(char *str);
	int		check_connections(char *str);
	int		check_last(char *str);
	int		check_all(char *av);
	char	**coordinates(char *av, int block_nb);
	int		find_min(int *map);
	int		*assign_spot(int *map, int *tet);
	int		ft_success(int *map, int *tet);
	int		*adjust_map(int *map, int *tetris);
	char	**initiate_map(int map_size);
	/*
	** Coordonnees file :
	*/
	char	*create_coord(char *buf);
	void	print_map(char **map, int map_size);

	/*
	** Solve file :
	*/
	int		size(char **map);
	char	**solve(char **map, char **tetris, 	int tetris_nb, char *spot, int i);

	/*
	** Algo_tool file :
	*/
	int		count_dots(char **map);
	char 	*reset_spot();
	int		find_max_letter(char **map);
	char	*find_first_spot(char **map, int max_letter);
	char	**free_map(char **map, int max_letter);
	char	**fill_map(char **map, char **tetris, int tr_n, char *spot);
	int		min_map_size(int tetris_nb);




#endif
