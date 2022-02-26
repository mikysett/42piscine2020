/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:07:05 by msessa            #+#    #+#             */
/*   Updated: 2020/11/26 18:18:43 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_num(char *num, int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		num[n - i] = '0' + n - i;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	r[n];
	int		i;
	int		j;

	ft_init_num(r, n);
	write(1, &r, n);
	i = n - 1;
	while (i >= 0)
	{
		if ((r[i] != '9' && i == n - 1) || (i != n - 1 && r[i] + 1 != r[i + 1]))
		{
			r[i]++;
			j = i + 1;
			while (j < n)
			{
				r[j] = r[j - 1] + 1;
				j++;
				i++;
			}
			write(1, ", ", 2);
			write(1, &r, n);
		}
		else
			i--;
	}
}
