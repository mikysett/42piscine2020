/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:22:56 by msessa            #+#    #+#             */
/*   Updated: 2020/11/28 20:28:08 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *dest_p;

	dest_p = dest;
	while (*(dest++) != '\0')
		continue;
	dest--;
	while (*src++ != '\0' && nb-- > 0)
	{
		*(dest++) = *(src - 1);
	}
	*dest = '\0';
	return (dest_p);
}
