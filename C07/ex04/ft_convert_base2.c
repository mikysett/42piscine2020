/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:03:19 by msessa            #+#    #+#             */
/*   Updated: 2020/12/04 08:03:24 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		init_position(char *nbr, int *neg, char *base_from);
int		ft_valid_base(char *b);
int		digit_in_base(char digit, char *base);
int		base_num_val(char digit, char *base);
int		set_digit(char *res, long int num, long int nb_base, char *base);
int		set_digit_neg(char *res, long int num, long int nb_base, char *base);
int		set_nb_digits(long int num, long int nb_base);
char	*ft_putnbr_base(int nbr, int nb_base, char *base);

int		init_position(char *nbr, int *neg, char *base_from)
{
	int i;
	int nb_digits;

	i = 0;
	while (nbr[i] != '\0' && (nbr[i] == ' ' || nbr[i] == '\f' || nbr[i] == '\n'
		|| nbr[i] == '\r' || nbr[i] == '\t' || nbr[i] == '\v'))
		i++;
	while (nbr[i] != '\0' && (nbr[i] == '-' || nbr[i] == '+'))
		if (nbr[i++] == '-')
			*neg = *neg == 1 ? -1 : 1;
	nb_digits = i;
	while (nbr[nb_digits] != '\0' && digit_in_base(nbr[nb_digits], base_from))
		nb_digits++;
	nb_digits -= i;
	return (nb_digits);
}

int		set_digit(char *res, long int num, long int nb_base, char *base)
{
	int position;

	position = 0;
	if (num >= nb_base)
		position = set_digit(res, num / nb_base, nb_base, base);
	res[position] = *(base + (num % nb_base));
	return (position + 1);
}

int		set_digit_neg(char *res, long int num, long int nb_base, char *base)
{
	int position;

	position = 0;
	if (num <= -nb_base)
		position = set_digit_neg(res, num / nb_base, nb_base, base);
	res[position + 1] = *(base + (num % nb_base) * -1);
	return (position + 1);
}

int		set_nb_digits(long int num, long int nb_base)
{
	int i;

	i = 0;
	if (num >= 0)
		while (num >= nb_base)
		{
			num /= nb_base;
			i++;
		}
	else
		while (num <= -nb_base)
		{
			num /= nb_base;
			i++;
		}
	i++;
	return (i);
}

char	*ft_putnbr_base(int nbr, int nb_base, char *base)
{
	int			nb_digits;
	char		*final_nbr;

	nb_digits = set_nb_digits(nbr, nb_base);
	if (nbr < 0)
		nb_digits++;
	final_nbr = malloc(sizeof(char) * (nb_digits + 1));
	if (!final_nbr)
		return (0);
	final_nbr[nb_digits] = '\0';
	if (nbr < 0)
	{
		final_nbr[0] = '-';
		set_digit_neg(final_nbr, nbr, nb_base, base);
	}
	else
		set_digit(final_nbr, nbr, nb_base, base);
	return (final_nbr);
}
