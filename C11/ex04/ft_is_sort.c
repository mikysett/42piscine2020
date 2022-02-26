/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:55:47 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 18:55:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int order;

	i = 0;
	order = 0;
	while (i < length)
	{
		if (!order && i + 1 < length && (*f)(tab[i], tab[i + 1]) > 0)
			order = 1;
		else if (!order && i + 1 < length && (*f)(tab[i], tab[i + 1]) < 0)
			order = -1;
		else if (order == -1 && i + 1 < length && (*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		else if (order == 1 && i + 1 < length && (*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
