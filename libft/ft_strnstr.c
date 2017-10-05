/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:16:20 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/25 11:16:34 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	int				find_index;
	int				remember;

	find_index = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[find_index])
		{
			remember = i;
			while (big[i] == little[find_index] && i < len)
			{
				if (little[find_index++ + 1] == '\0')
					return ((char*)&big[remember]);
				i++;
			}
			find_index = 0;
			i = remember;
		}
		i++;
	}
	return (0);
}
