/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonnees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:26:55 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/18 14:35:04 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"


t_tetris *coord_attach(t_tetris *current, char *buf)
{
	int i;

	i = 0;
	while (i++ < 4)
		current->coord[i] = create_coord(buf)[i];
	current = current->next;
	return (current);
}

void print_list(t_tetris *current)
{
	int i;
	i = 0;
	while (current->next != NULL)
	{
		printf("%d- \n", current->numero);
		while (i++ < 4)
    		printf("%d ", current->coord[i]);
		printf("\n");
    	current = current->next;
	}
}

int *create_coord(char *buf)
{
	int i;
	int j;
	int k;
	static int array[4];

	i = 0;
	j = 0;
	k = 0;
	while (buf[i] != '#')
		i++;
	while (buf[i])
	{
		if (buf[i] == '\n')
			j = j + 9;
		if (buf[i] == '#')
		{
			k++;
			array[k] = j;
		}
		j++;
		i++;
	}
	return (array);
}

t_tetris *create_element(void *buf)
{
	t_tetris *current;
	int i;

	current = (t_tetris *)malloc(sizeof(t_tetris));
	i = 0;

	while (i++ < 4)
		current->coord[i] = 0;

	current->numero = 0;

	current->next = NULL;

	return (current);
}
void fill_list(t_tetris **head, char *buf)
{
	int tetris_number;
	tetris_number = 0;
	t_tetris *tail;
	t_tetris *temp;

	tail = create_element(NULL);
	tetris_number++;
	tail->numero = tetris_number;
	temp = *head;
	*head = tail;
	(*head)->next = temp;
}

t_tetris *add_tetris(char *av, t_tetris **head)
{
	int 	i;
	char	*buf;
	int		fd;

	i = 0;
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(av, O_RDONLY);

	while (read(fd, buf, 21) != 0)
		fill_list(head, buf);
	print_list(*head);
	free(buf);
	return (*head);
}

int		main(int ac, char **av)
{
	if (check_all(ac, av) == 0)
		return (0);
	t_tetris	**tetris;
	t_tetris = (cast t_tetris **malloc(sizeof(t_tetris **));
	*tetris = create_element(NULL);
	printf("hello \n");

	add_tetris(av[1], tetris);

	free(tetris);
	return (0);
}


int *cut_array(int *tetris, int block_nb)
{
	int i;
	int block[4];

	i = 4 * (block_nb - 1);
	block[0] = tetris[i];
	block[1] = tetris[i + 1];
	block[2] = tetris[i + 2];
	block[3] = tetris[i + 3];
	return (block);
}
