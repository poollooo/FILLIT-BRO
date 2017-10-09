/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/08 21:29:40 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

struct t_map
	{
		int m_distance[196];
		char m_letters[196];
	};
struct t_tetri
	{
		int numero;
		char m_coord[4];
	};

int		main(int argc, char **argv)
{
	t_list	*list;
	t_list	*map;
	int fd;
	char *buf;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}

	/*
	** read_tetri is the function that will read the tetris pieces and checks if
	** it's valid or not.
	** O_RDONLY stand for "Open for reading only"
	*/

	if (read_tetriminos(open(argv[1])) == NULL) // A refaire mieux.
	{
		ft_putstr("error\n");
		return (1);
	}

	/*
	** We still need to figure out how we are going to solve this fucking problem.
	*/

	buf = (char *)malloc(22);
	ft_bzero(buf, 22)
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 21);

}
