/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:00:25 by msessa            #+#    #+#             */
/*   Updated: 2020/12/10 12:00:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *curr;

	curr = *begin_list;
	if (!curr)
		*begin_list = ft_create_elem(data);
	else
		while (curr)
		{
			if (curr->next == 0)
			{
				curr->next = ft_create_elem(data);
				return ;
			}
			curr = curr->next;
		}
}
