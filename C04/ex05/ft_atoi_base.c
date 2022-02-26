/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:55:27 by msessa            #+#    #+#             */
/*   Updated: 2020/11/30 16:28:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_is_valid(char *b);
int	digit_in_base(char digit, char *base);
int	base_num_val(char digit, char *base);
int	change_base(char *str, int nb_digits, int nb_base, char *base);
int	ft_atoi_base(char *str, char *base);

int	base_is_valid(char *b)
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

int	digit_in_base(char digit, char *base)
{
	while (*base != '\0' && *base != digit)
		base++;
	if (*base == '\0')
		return (0);
	return (1);
}

int	base_num_val(char digit, char *base)
{
	int i;

	i = 0;
	while (base[i] != digit)
		i++;
	return (i);
}

int	change_base(char *str, int nb_digits, int nb_base, char *base)
{
	int powers[nb_digits];
	int i;
	int res;

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

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int neg;
	int res;
	int nb_base;
	int nb_digits;

	if ((nb_base = base_is_valid(base)) < 2)
		return (0);
	i = 0;
	neg = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			neg = neg == 1 ? -1 : 1;
	nb_digits = i;
	while (str[nb_digits] != '\0' && digit_in_base(str[nb_digits], base))
		nb_digits++;
	nb_digits -= i;
	res = change_base((str + i), nb_digits, nb_base, base);
	return (res * neg);
}
