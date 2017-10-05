/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/05 15:42:32 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

int		main(int argc, char **argv)
{
	t_list	*list;
	t_list	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}

	/*
	** read_tetri i the function that will read the tetris pieces and checks if
	** it's valid or not.
	** O_RDONLY stand for "Open for reading only"
	*/

	if ((list = read_tetri(open(argv[1]))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}

	/*
	**We still need to figure out how we are going to solve this fucking problem.
	*/
}
