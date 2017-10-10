/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:20:54 by pnizet            #+#    #+#             */
/*   Updated: 2017/09/22 11:07:10 by pnizet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *retval;

	retval = (t_list*)malloc(sizeof(t_list));
	if (retval == NULL)
		return (NULL);
	if (content == NULL)
	{
		retval->content = NULL;
		retval->content_size = 0;
	}
	else
	{
		retval->content = malloc(content_size);
		if (content == NULL)
		{
			free(retval);
			return (NULL);
		}
		ft_memcpy(retval->content, content, content_size);
		retval->content_size = content_size;
	}
	retval->next = NULL;
	return (retval);
}
