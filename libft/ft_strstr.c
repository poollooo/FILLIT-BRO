/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:42:01 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 11:07:42 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *ts1;
	char *ts2;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		ts1 = (char *)s1;
		ts2 = (char *)s2;
		while (*ts2 && *ts1 == *ts2)
		{
			ts1++;
			ts2++;
		}
		if (*ts2 == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
