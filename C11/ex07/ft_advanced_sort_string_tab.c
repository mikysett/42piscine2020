/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:53:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/09 09:53:32 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_set_tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		tab_size;
	int		i;
	char	*buff;
	int		sorted;

	i = 0;
	sorted = 0;
	tab_size = ft_set_tab_size(tab);
	while (i < tab_size - 1)
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
		{
			buff = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buff;
			sorted = 0;
		}
		i++;
		if (i == tab_size - 1 && sorted == 0)
		{
			sorted = 1;
			i = 0;
		}
	}
}
