/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:25:17 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 14:29:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(char c)
{
	char	res[2];
	char	hex_d;
	int		i;
	int		c_int;

	res[0] = '0';
	res[1] = '0';
	i = 1;
	if (c < 0)
		c_int = 256 + c;
	else
		c_int = c;
	while (i >= 0)
	{
		hex_d = c_int % 16;
		if (hex_d > 9)
			res[i] = 'a' + (hex_d - 10);
		else
			res[i] = '0' + hex_d;
		c_int /= 16;
		i--;
	}
	write(1, res, 2);
}
