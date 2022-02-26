/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:11:27 by msessa            #+#    #+#             */
/*   Updated: 2020/11/28 20:20:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *dest_p;

	dest_p = dest;
	while (*(dest++) != '\0')
		continue;
	dest--;
	while (*src++ != '\0')
	{
		*(dest++) = *(src - 1);
	}
	*dest = '\0';
	return (dest_p);
}