/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:10:50 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 11:06:24 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *strsrc;
	char *strdst;

	strsrc = (char*)src;
	strdst = (char*)dst;
	while (n > 0 && *strsrc != c)
	{
		n--;
		*strdst++ = *strsrc++;
	}
	if (n > 0)
	{
		*strdst++ = *strsrc++;
		return ((void*)strdst);
	}
	else
		return (NULL);
}
