/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:25:04 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 13:25:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	if (!root)
		return (0);
	if (root->left && (*cmpf)(root->left->item, data_ref) >= 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	if (root->right && (*cmpf)(root->right->item, data_ref) <= 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	return (0);
}
