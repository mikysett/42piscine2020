/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:23:03 by msessa            #+#    #+#             */
/*   Updated: 2020/12/02 18:05:14 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++ && *(s1 - 1) && *(s2 - 1))
		continue;
	return (*(s1 - 1) - *(s2 - 1));
}

void	ft_printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*buff;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				buff = argv[i];
				argv[i] = argv[j];
				argv[j] = buff;
			}
			j++;
		}
		ft_printstr(argv[i]);
		i++;
	}
	return (0);
}
