/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:25:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/09 08:25:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_add(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int	ft_rm(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int	ft_multi(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int	ft_div(int nb1, int nb2)
{
	return (nb1 / nb2);
}

int	ft_mod(int nb1, int nb2)
{
	return (nb1 % nb2);
}
