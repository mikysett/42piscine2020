/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:27:20 by msessa            #+#    #+#             */
/*   Updated: 2020/11/30 20:40:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(long int num, long int nb_base, char *base)
{
	if (num >= nb_base)
		print_digit(num / nb_base, nb_base, base);
	write(1, (base + (num % nb_base)), 1);
}

void	ft_putnbr_hex(long int nbr, int c_op)
{
	long int	nb_base;
	int			nb_digits;
	long int	nb_buff;
	int			i;

	nb_digits = 1;
	nb_buff = nbr;
	nb_base = 16;
	i = 7;
	if (c_op)
		i++;
	while (nb_buff / 16 > 0)
	{
		nb_buff /= 16;
		nb_digits++;
	}
	while (i-- > nb_digits)
		write(1, "0", 1);
	print_digit(nbr, nb_base, "0123456789abcdef");
}
