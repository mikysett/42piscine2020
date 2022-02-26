/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:32:14 by msessa            #+#    #+#             */
/*   Updated: 2020/12/09 09:32:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++ && *(s1 - 1) && *(s2 - 1))
		continue;
	return (*(s1 - 1) - *(s2 - 1));
}

int		ft_set_tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int		tab_size;
	int		i;
	int		j;
	char	*buff;

	i = 0;
	tab_size = ft_set_tab_size(tab);
	while (i < tab_size)
	{
		j = i + 1;
		while (j < tab_size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				buff = tab[i];
				tab[i] = tab[j];
				tab[j] = buff;
			}
			j++;
		}
		i++;
	}
}
