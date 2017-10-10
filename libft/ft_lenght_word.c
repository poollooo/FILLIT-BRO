/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 12:21:17 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/02 20:39:53 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_lenght_word(char const *s, char c)
{
	size_t lenght;
	size_t i;

	lenght = 0;
	i = 0;
	if (!s || !c)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		lenght++;
	}
	printf("%lu\n", lenght + 3);
	return (lenght + 1);
}
