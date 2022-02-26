/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:07:36 by msessa            #+#    #+#             */
/*   Updated: 2020/12/04 16:40:20 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*src_cp;

	i = 0;
	while (src[i])
		i++;
	if (i == 0)
	{
		src_cp = malloc(sizeof(char));
		src_cp[0] = '\0';
		return (src_cp);
	}
	i++;
	src_cp = malloc(sizeof(char) * i);
	j = 0;
	while (j < i)
	{
		src_cp[j] = src[j];
		j++;
	}
	return (src_cp);
}
