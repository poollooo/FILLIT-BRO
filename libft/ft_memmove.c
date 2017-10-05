/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:26:34 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 17:50:05 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*x;
	char		*y;

	x = (char *)dst;
	y = (char *)src;
	if (x > y)
	{
		while (len--)
			x[len] = y[len];
	}
	else
		ft_memcpy(x, y, len);
	return (x);
}
