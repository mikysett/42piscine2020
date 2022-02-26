/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:13:25 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 11:13:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_invert_first_last(t_list *begin_list, t_list *prev)
{
	t_list	*curr;
	void	*buff_data;

	curr = prev;
	if (!curr || !(curr->next))
		return ;
	while (curr)
	{
		if (!(curr->next->next))
		{
			curr->next = prev;
			break ;
		}
		curr = curr->next;
	}
	buff_data = begin_list->data;
	begin_list->data = prev->data;
	begin_list->next = prev->next;
	prev->data = buff_data;
	prev->next = 0;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	curr = begin_list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	ft_invert_first_last(begin_list, prev);
}
