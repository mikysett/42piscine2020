/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:24:39 by msessa            #+#    #+#             */
/*   Updated: 2020/12/04 12:24:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);
int		ft_set_tot_mem(int size, char **strs, char *sep);
char	*ft_strjoin(int size, char **strs, char *sep);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int		ft_set_tot_mem(int size, char **strs, char *sep)
{
	int	sep_size;
	int tot_mem;
	int i;

	sep_size = ft_strlen(sep);
	tot_mem = 0;
	i = 0;
	while (i < size)
	{
		tot_mem += ft_strlen(strs[i]);
		i++;
	}
	return (tot_mem + ((size - 1) * sep_size) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		tot_mem;
	int		i;

	result = 0;
	if (size <= 0)
	{
		result = malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	tot_mem = ft_set_tot_mem(size, strs, sep);
	result = malloc(sizeof(char) * tot_mem);
	*result = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcpy(result, strs[i]);
		if (i + 1 != size)
			ft_strcpy(result, sep);
		i++;
	}
	return (result);
}
