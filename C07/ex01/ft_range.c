/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:22:46 by msessa            #+#    #+#             */
/*   Updated: 2020/12/03 09:04:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int size;
	int i;
	int *res;

	if (min >= max)
		return (0);
	size = max - min;
	i = 0;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	while (i < size)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
