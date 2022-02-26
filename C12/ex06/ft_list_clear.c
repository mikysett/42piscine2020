/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:46:26 by msessa            #+#    #+#             */
/*   Updated: 2020/12/10 13:46:35 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *to_delete;

	while (begin_list)
	{
		to_delete = begin_list;
		begin_list = begin_list->next;
		(*free_fct)(to_delete->data);
		free(to_delete);
	}
}
