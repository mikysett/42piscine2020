/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:11:28 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 14:12:00 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		ft_is_first(t_btree *root, t_btree **firsts, int max_level)
{
	int i;

	i = 0;
	while (i <= max_level)
	{
		if (firsts[i] == root)
			return (1);
		i++;
	}
	return (0);
}

void	ft_apply_by_level(t_btree **root, int level, int max_level,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first;

	if (*root)
	{
		is_first = ft_is_first(*root, root, max_level);
		(*applyf)((*root)->item, level, is_first);
	}
	else
		return ;
	ft_apply_by_level(&((*root)->left), level + 1, max_level, applyf);
	ft_apply_by_level(&((*root)->right), level + 1, max_level, applyf);
}

int		btree_level_count(t_btree *root)
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

int		ft_init_firsts_in_line(t_btree *root, t_btree **firsts_in_line,
	int curr_lev, int upper_level)
{
	int upper_level_lx;
	int upper_level_dx;

	if (!root)
		return (curr_lev);
	if (curr_lev >= upper_level)
	{
		firsts_in_line[curr_lev] = root;
		upper_level++;
	}
	upper_level_lx = ft_init_firsts_in_line(root->left,
		firsts_in_line, curr_lev + 1, upper_level);
	upper_level_dx = ft_init_firsts_in_line(root->right,
		firsts_in_line, curr_lev + 1, upper_level_lx);
	if (upper_level_lx >= upper_level_dx)
		return (upper_level_lx);
	return (upper_level_dx);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_btree	**firsts_in_line;
	int		max_lev;

	if (!root)
		return ;
	max_lev = btree_level_count(root);
	firsts_in_line = malloc(sizeof(t_btree *) * (max_lev + 1));
	if (!firsts_in_line)
		return ;
	ft_init_firsts_in_line(root, firsts_in_line, 0, 0);
	ft_apply_by_level(firsts_in_line, 0, max_lev, applyf);
	free(firsts_in_line);
}
