/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:34:00 by msessa            #+#    #+#             */
/*   Updated: 2020/11/29 14:46:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		neg_check(int *nb)
{
	if (*nb < 0)
	{
		write(1, "-", 1);
		if (*nb == -2147483648)
		{
			*nb = 2147483647;
			return (1);
		}
		else
			*nb *= -1;
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	long int	dec;
	long int	buff;
	int			last_neg;

	last_neg = neg_check(&nb);
	dec = 1;
	while (nb / (dec * 10) > 0)
		dec *= 10;
	buff = nb / dec;
	while (dec > 0)
	{
		if (dec == 1 && last_neg == 1)
			ft_putchar('8');
		else
			ft_putchar('0' + buff);
		nb -= (buff * dec);
		dec /= 10;
		if (dec != 0)
			buff = nb / dec;
	}
}
