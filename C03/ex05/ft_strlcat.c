/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:31:23 by msessa            #+#    #+#             */
/*   Updated: 2020/11/29 13:37:29 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len_src;

	i = 0;
	len_src = 0;
	while (dest[i] != '\0')
		i++;
	while (src[len_src] != '\0')
		len_src++;
	if (size > i)
		len_src += i;
	else
		len_src += size;
	while (*src++ != '\0' && i < size - 1)
	{
		dest[i] = *(src - 1);
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}
