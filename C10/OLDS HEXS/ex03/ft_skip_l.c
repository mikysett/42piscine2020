/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_identic_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:03:41 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 15:03:45 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_skip_l(char *addr, unsigned int line1, int nb_lines, int count)
{
	unsigned int	line2;

	line2 = line1;
	line1 -= 16;
	while (addr[line1] && addr[line2])
	{
		if (addr[line1++] == addr[line2++])
		{
			count++;
			if (count == 16)
			{
				line1 -= 16;
				count = 0;
				nb_lines++;
			}
		}
		else
			break ;
	}
	if (nb_lines > 0)
		write(1, "*\n", 2);
	return (nb_lines * 16);
}
