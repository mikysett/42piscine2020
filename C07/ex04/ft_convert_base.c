/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:02:16 by msessa            #+#    #+#             */
/*   Updated: 2020/12/04 08:12:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		init_position(char *nbr, int *neg, char *base_from);
int		valid_base(char *b);
int		digit_in_base(char digit, char *base);
int		base_num_val(char digit, char *base);
int		set_digit(char *res, long int num, long int nb_base, char *base);
int		set_digit_neg(char *res, long int num, long int nb_base, char *base);
int		set_nb_digits(long int num, long int nb_base);
char	*ft_putnbr_base(int nbr, int nb_base, char *base);

int		valid_base(char *b)
{
	int i;
	int j;

	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == '+' || b[i] == '-' || b[i] == ' ' || b[i] == '\f'
			|| b[i] == '\n' || b[i] == '\r' || b[i] == '\t' || b[i] == '\v')
			return (0);
		j = i + 1;
		while (b[j] != '\0')
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		digit_in_base(char digit, char *base)
{
	while (*base != '\0' && *base != digit)
		base++;
	if (*base == '\0')
		return (0);
	return (1);
}

int		base_num_val(char digit, char *base)
{
	int i;

	i = 0;
	while (base[i] != digit)
		i++;
	return (i);
}

int		change_base(char *str, int nb_digits, int nb_base, char *base)
{
	int powers[nb_digits];
	int i;
	int res;

	while (*str != '\0' && (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v'
		|| *str == '-' || *str == '+'))
		str++;
	i = 1;
	powers[0] = 1;
	res = 0;
	while (i++ < nb_digits)
		powers[i - 1] = powers[i - 2] * nb_base;
	i = 0;
	while (str[i] != '\0' && digit_in_base(str[i], base))
	{
		nb_digits--;
		res += base_num_val(str[i], base) * powers[nb_digits];
		i++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		*neg_p;
	int		neg;
	int		nb_base[2];
	int		nb_digits;
	int		nbr_dec;

	neg = 1;
	neg_p = &neg;
	if ((nb_base[0] = valid_base(base_from)) < 2
		|| (nb_base[1] = valid_base(base_to)) < 2)
		return (0);
	nb_digits = init_position(nbr, neg_p, base_from);
	nbr_dec = (change_base(nbr, nb_digits, nb_base[0], base_from)) * *neg_p;
	return (ft_putnbr_base(nbr_dec, nb_base[1], base_to));
}
