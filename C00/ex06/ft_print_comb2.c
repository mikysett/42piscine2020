/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:25:22 by msessa            #+#    #+#             */
/*   Updated: 2020/11/26 15:17:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_num_init(char *num)
{
	num[0] = '0';
	num[1] = '0';
	num[2] = ' ';
	num[3] = '0';
	num[4] = '1';
}

void	ft_num_increment(char *num)
{
	if (num[3] == '9' && num[4] == '9')
	{
		if (num[1] != '9')
			num[1]++;
		else
		{
			num[0]++;
			num[1] = '0';
		}
		num[3] = num[0];
		num[4] = num[1];
	}
	if (num[4] != '9')
		num[4]++;
	else
	{
		num[3]++;
		num[4] = '0';
	}
}

void	ft_print_comb2(void)
{
	char num[5];

	ft_num_init(num);
	while (num[0] != '9' || num[1] != '9')
	{
		write(1, &num, 5);
		if (num[0] != '9' || num[1] != '8' || num[3] != '9' || num[4] != '9')
			write(1, ", ", 2);
		ft_num_increment(num);
	}
}
