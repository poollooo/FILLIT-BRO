/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compt_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 12:20:16 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/25 11:11:35 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_compt_word(char const *s, char c)
{
	size_t	nb;
	size_t	i;
	int		boolean;

	i = 0;
	nb = 0;
	boolean = 1;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c && boolean)
		{
			nb++;
			boolean = 0;
		}
		else if (s[i] == c)
			boolean = 1;
		i++;
	}
	return (nb);
}
