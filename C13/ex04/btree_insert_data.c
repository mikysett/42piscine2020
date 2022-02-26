/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:32:26 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 09:32:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)((*root)->item, item) > 0)
	{
		if (!((*root)->left))
			(*root)->left = btree_create_node(item);
		else
			btree_insert_data(&((*root)->left), item, cmpf);
	}
	else
	{
		if (!((*root)->right))
			(*root)->right = btree_create_node(item);
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
}
