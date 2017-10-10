/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/09 17:41:27 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

int		main(int argc, char **argv)
{
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

	// if (read_tetriminos(open(argv[1])) == NULL) // A refaire mieux.
	// {
	// 	ft_putstr("error\n");
	// 	return (1);
	// }

	/*
	** We still need to figure out how we are going to solve this fucking problem.
	*/

	buf = (char *)malloc(22);
	ft_bzero(buf, 22);
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 21);

}
