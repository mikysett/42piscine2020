/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:15:54 by msessa            #+#    #+#             */
/*   Updated: 2020/11/26 12:23:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char digits[3];

	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	while (digits[0] != '8')
	{
		write(1, &digits, 3);
		if (digits[0] != '7' || digits[1] != '8' || digits[2] != '9')
			write(1, ", ", 2);
		if (digits[2] != '9')
			digits[2]++;
		else if (digits[1] != '8')
		{
			digits[1]++;
			digits[2] = digits[1] + 1;
		}
		else
		{
			digits[0]++;
			digits[1] = digits[0] + 1;
			digits[2] = digits[1] + 1;
		}
	}
}
