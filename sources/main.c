/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/16 22:07:41 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

int		main(int ac, char **av)
{
	if (check_all(int ac, char **av) == 0)
		return (0);
	else
		print(solve(coordinates(av[1])));
	return (0);
}

void print_list(t_tetris *head)
{
	int i;
    t_tetris *current = head;
	i = 0;
	while (i++ < 4)
    	printf("%d ", current->coord[i]);
    current = current->next;
}
