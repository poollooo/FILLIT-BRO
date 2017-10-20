/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 23:35:17 by jostraye          #+#    #+#             */
/*   Updated: 2017/10/19 16:28:59 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/* The idea is to create a recursive function that will lead to writting the
last tetris first, calling back to the first one */

void print_array(int *array, int block_nb)
{
	int i;

	i = 0;
	while (i < block_nb * 4)
	{
		if (i % 4 == 0)
			printf("\n");
		printf("%d ", array[i]);
		i++;
	}
	printf("%d \n", array[i]);
	printf("\n");
}

int	*create_coord(char *buf, int block_nb)
{
	int i;
	int j;
	int k;
	static int *array;

	array = malloc(sizeof(int) * 4 * block_nb + 2);
	i = 0;
	j = 0;
	k = 0;
	while (buf[i] != '#')
		i++;
	while (buf[i])
	{
		if (buf[i - 1] == '\n' && buf[i] == '\n')
		{
			while (buf[i] != '#')
				i++;
			j = 0;
		}
		if (buf[i] == '\n' && buf[i + 1] != '\n')
			j = j + 9;
		if (buf[i] == '#')
			array[k++] = j;
		j++;
		i++;

	}
	return (array);
}

int *read_input(char *av, int block_nb)
{
	int 	i;
	char	*buf;
	int		fd;
	static int *array;

	array = malloc(sizeof(int) * 4 * block_nb + 2);
	i = 0;
	buf = (char *)malloc(22 * block_nb * sizeof(char));
	fd = open(av, O_RDONLY);
	while (read(fd, buf, 21 * block_nb) != 0)
		while (i < block_nb * 4)
		{
			array[i] = create_coord(buf, block_nb)[i];
			i++;
		}
		array[i] = -1;
	return (array);
}

int		*coordinates(char *av, int block_nb)
{
	static int *array;
	block_nb += 1;
	array = malloc(sizeof(int) * 4 * block_nb + 1);
	if (array == NULL)
		return (0);
	array = read_input(av, block_nb);
	print_array(array, block_nb);
	return (array);
}
