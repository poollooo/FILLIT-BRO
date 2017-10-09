/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:30:41 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/08 21:17:34 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
** Verifie que les tetriminos ont une bonne shape general et verifie
** s'il y a bien 4 '#' et 12 "."
*/

int		check_shape(char *str)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = 0;

	while (str[i])
	{
		if (str[i] == '#')
			j++;
		if (str[i] == '.')
			k++;
		i++;
	}
	if ((str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
	|| (str[20] != '\0' && str[20] != '\n'))
		return (0);
	if (j != 4 || k != 12)
		return (0);
	else
		return (1);
}

int		check_connections(char *str)
{
	int i;
	int connections;

	i = 0;
	connections =0 ;
	while (str[i])
	{
		if(str[i] == '#')
		{
			if(str[i + 1] && str[i + 1] == '#')
				connections++;
			if(str[i - 1] && str[i - 1] == '#')
				connections++;
			if(str[i + 5] && str[i + 5] == '#')
				connections++;
			if(str[i - 5] && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	else
		return (0);
}

int		check_last(char *str)
{
	int i;

	printf("%s", str);
	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n' && (str[i - 2] == '.' || str[i - 2] == '#'))
		return (1);
	else
		return (0);

}

int main(int ac, char **av)
{
	int fd;
	char *buf;
	int block_nb;
	char *str;
	if (ac != 2)
	{
		printf("usage: fillit input_file\n");
		return (1);
	}

	/*
	** read_tetri is the function that will read the tetris pieces and checks if
	** it's valid or not.
	** O_RDONLY stand for "Open for reading only"
	*/

	block_nb = 0;
	buf = (char *)malloc(22);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buf, 21) != 0)
	{
		if(check_shape(buf) == 1)
			printf("Shape ");
		if(check_shape(buf) == 0)
			printf("SX ");
		if(check_connections(buf) == 1)
			printf("Connexion \n");
		if(check_connections(buf) == 0)
			printf("CX \n");
		if (check_connections(buf) == 0 || check_shape(buf) == 0)
			printf("error\n");
		block_nb++;
		printf("%d \n", block_nb);
	}
	fd = open(av[1], O_RDONLY);
	str = (char *)malloc(22 * block_nb);
	read(fd, str, 21 * block_nb);
	if (check_last(str) == 0)
		printf("error de fin\n");
	else
		printf("Hehe\n");
	return (0);
}
