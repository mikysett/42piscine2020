/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:26:59 by msessa            #+#    #+#             */
/*   Updated: 2020/11/30 19:47:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int res;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = 1;
	res = nb;
	while (i < nb)
	{
		res *= (nb - i);
		i++;
	}
	return (res);
}
