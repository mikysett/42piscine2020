/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:48:09 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 13:48:32 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_max;
	int	right_max;

	if (root)
	{
		left_max = btree_level_count(root->left);
		right_max = btree_level_count(root->right);
		if (left_max > right_max)
			return (left_max + 1);
		else
			return (right_max + 1);
	}
	return (0);
}
