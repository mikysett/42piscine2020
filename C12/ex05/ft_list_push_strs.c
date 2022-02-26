/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:33:58 by msessa            #+#    #+#             */
/*   Updated: 2020/12/10 13:34:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;
	t_list	*tracker;

	i = size - 1;
	begin = 0;
	while (i >= 0)
	{
		if (begin)
		{
			tracker->next = ft_create_elem(strs[i]);
			tracker = tracker->next;
		}
		else
		{
			begin = ft_create_elem(strs[i]);
			tracker = begin;
		}
		i--;
	}
	return (begin);
}
