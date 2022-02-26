/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:15:31 by msessa            #+#    #+#             */
/*   Updated: 2020/12/02 14:02:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long int square;

	if (nb == 1 || nb == -1)
		return (1);
	if (nb == 0 || nb == -2147483648)
		return (0);
	nb = nb < 0 ? nb * -1 : nb;
	square = 2;
	while (square * square < nb)
		square++;
	if (square * square == nb)
		return (square);
	return (0);
}

int main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
	printf("%d\n", ft_sqrt(2147483646));
	printf("%d\n", ft_sqrt(2147483645));
	printf("%d\n", ft_sqrt(2147483644));
	printf("%d\n", ft_sqrt(2147483643));
	printf("%d\n", ft_sqrt(2147483642));
	printf("%d\n", ft_sqrt(2147483641));
	printf("%d\n", ft_sqrt(2147483640));
	printf("%d\n", ft_sqrt(214748364));
	printf("%d\n", ft_sqrt(21474836));
	printf("%d\n", ft_sqrt(400));
	printf("%d\n", ft_sqrt(214748347));
	printf("%d\n", ft_sqrt(214483647));
	printf("%d\n", ft_sqrt(2147483627));
	printf("%d\n", ft_sqrt(2147283647));
	return (0);
}
