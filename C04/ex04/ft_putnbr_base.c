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

int		base_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_digit(long int num, long int nb_base, char *base)
{
	if (num >= nb_base)
		print_digit(num / nb_base, nb_base, base);
	write(1, (base + (num % nb_base)), 1);
}

void	print_digit_neg(long int num, long int nb_base, char *base)
{
	if (num <= nb_base)
		print_digit_neg(num / -nb_base, nb_base, base);
	write(1, (base + (num % nb_base) * -1), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb_base;

	if ((nb_base = base_is_valid(base)) < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_digit_neg(nbr, -nb_base, base);
	}
	else
		print_digit(nbr, nb_base, base);
}
