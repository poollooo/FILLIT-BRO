/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 01:39:22 by pnizet            #+#    #+#             */
/*   Updated: 2017/10/26 01:48:28 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	*ft_memset(void *str, int data, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)str;
	while (len-- > 0)
		*ptr++ = (unsigned char)data;
	return (str);
}
