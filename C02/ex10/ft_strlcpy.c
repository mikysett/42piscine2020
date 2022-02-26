/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:38:45 by msessa            #+#    #+#             */
/*   Updated: 2020/11/28 17:13:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (i < size)
	{
		if (i < len_src)
		{
			*(dest + i) = *(src + i);
		}
		else
			*(dest + i) = '\0';
		i++;
	}
	return (len_src);
}
