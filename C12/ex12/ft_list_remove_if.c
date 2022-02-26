/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:32:15 by msessa            #+#    #+#             */
/*   Updated: 2020/12/11 14:32:18 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list *prev;
	t_list *next;
	t_list *current;

	prev = 0;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		if (!(*cmp)(current->data, data_ref))
		{
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			(*free_fct)(current->data);
			free(current);
		}
		else
			prev = current;
		current = next;
	}
}
