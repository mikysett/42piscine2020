/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:24:19 by msessa            #+#    #+#             */
/*   Updated: 2020/12/10 11:24:24 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}
