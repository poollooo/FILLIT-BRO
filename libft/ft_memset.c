/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:23:58 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 11:07:10 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int data, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)str;
	while (len-- > 0)
		*ptr++ = (unsigned char)data;
	return (str);
}
