/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:13:43 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 11:13:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_insert_el(t_list *curr, t_list *new_el)
{
	t_list	*next;

	next = curr->next;
	curr->next = new_el;
	new_el->next = next;
}

t_list	*ft_swap_lists(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*buff;

	buff = *begin_list1;
	*begin_list1 = begin_list2;
	return (buff);
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*curr;
	t_list	*next;

	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else if (begin_list2
		&& (*cmp)((*begin_list1)->data, begin_list2->data) > 0)
		begin_list2 = ft_swap_lists(begin_list1, begin_list2);
	curr = *begin_list1;
	while (curr && begin_list2)
	{
		next = curr->next;
		if (!next)
			curr->next = begin_list2;
		else if ((*cmp)(curr->data, begin_list2->data) <= 0
			&& (*cmp)(curr->data, begin_list2->data) > 0)
		{
			ft_insert_el(curr, begin_list2);
			begin_list2 = begin_list2->next;
			next = curr->next;
		}
		curr = next;
	}
}
