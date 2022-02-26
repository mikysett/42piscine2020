/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pos_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:19:23 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:19:25 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_digit(long int num, long int nb_base, char *base)
{
	if (num >= nb_base)
		print_digit(num / nb_base, nb_base, base);
	write(1, (base + (num % nb_base)), 1);
}

void	ft_print_pos_mem(long int nbr)
{
	int			nb_digits;
	long int	nb_buff;
	int			i;

	nb_digits = 1;
	nb_buff = nbr;
	i = 7;
	if (g_c_opt)
		i++;
	while (nb_buff / 16 > 0)
	{
		nb_buff /= 16;
		nb_digits++;
	}
	while (i-- > nb_digits)
		write(1, "0", 1);
	print_digit(nbr, 16, "0123456789abcdef");
}
