/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:13:34 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 11:13:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_apply_sort(t_list *curr, t_list *new_el, int (*cmp)())
{
	t_list *next;

	while (curr)
	{
		next = curr->next;
		if (!next)
			curr->next = new_el;
		else if ((*cmp)(curr->data, new_el->data) <= 0
			&& (*cmp)(next->data, new_el->data) > 0)
		{
			curr->next = new_el;
			new_el->next = next;
			return ;
		}
		curr = next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *new_el;
	t_list *curr;

	new_el = ft_create_elem(data);
	curr = *begin_list;
	if (!curr)
		*begin_list = new_el;
	else if ((*cmp)(curr->data, new_el->data) > 0)
	{
		new_el->next = curr;
		*begin_list = new_el;
		return ;
	}
	else
		ft_apply_sort(curr, new_el, cmp);
}
