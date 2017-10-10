/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:41:14 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 11:03:27 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	is_neg;
	int	number;

	is_neg = 0;
	number = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == 45)
		is_neg = 1;
	if ((*str == 45) || (*str == 43))
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		number *= 10;
		number += ((int)*str - 48);
		str++;
	}
	if (is_neg)
		return (-number);
	else
		return (number);
}
