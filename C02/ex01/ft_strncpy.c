/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:31:55 by msessa            #+#    #+#             */
/*   Updated: 2020/11/27 09:31:58 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (i < n)
	{
		if (i < len_src)
		{
			*(dest + i) = *(src + i);
		}
		else
			*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
