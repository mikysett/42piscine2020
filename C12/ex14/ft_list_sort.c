/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:13:16 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 11:13:18 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_swap_el(t_list **beg, t_list **curr, t_list **prev, t_list **next)
{
	t_list *buff;

	(*curr)->next = (*next)->next;
	(*next)->next = *curr;
	if (*prev)
		(*prev)->next = *next;
	else
		*beg = *next;
	buff = *curr;
	*curr = *next;
	*next = buff;
	return (0);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;
	int		is_ordered;

	curr = *begin_list;
	prev = 0;
	is_ordered = 1;
	while (curr && curr->next)
	{
		next = curr->next;
		if (next && (*cmp)(curr->data, next->data) > 0)
			is_ordered = ft_swap_el(begin_list, &curr, &prev, &next);
		prev = curr;
		curr = curr->next;
		if (!next->next && !is_ordered)
		{
			curr = *begin_list;
			prev = 0;
			is_ordered = 1;
		}
	}
}
