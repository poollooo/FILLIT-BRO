/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:13 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/11 14:44:57 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Main function, where we will use all our functions to solve the fillit
** problem.
*/

int		main(int ac, char **av)
{
	if (check_all(int ac, char **av) == 3)
		print(solve(coordonnees(av[1])));
	return (0);
}
