/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:13:06 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 11:13:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current)
	{
		if (!(current->next))
			break ;
		current = current->next;
	}
	current->next = begin_list2;
}
