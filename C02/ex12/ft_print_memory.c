/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:39:24 by msessa            #+#    #+#             */
/*   Updated: 2020/11/28 13:28:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_digit_size(uintptr_t n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

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

void	ft_print_pt(uintptr_t c, int digit_size)
{
	char	res[digit_size];
	char	hex_d;
	int		i;

	i = 0;
	while (i < digit_size)
	{
		res[i] = '0';
		i++;
	}
	i = digit_size - 1;
	while (i >= 0)
	{
		hex_d = c % 16;
		if (hex_d > 9)
			res[i] = 'a' + (hex_d - 10);
		else
			res[i] = '0' + hex_d;
		c /= 16;
		i--;
	}
	write(1, res, digit_size);
	write(1, ": ", 2);
}

void	ft_print_str(char *addr, unsigned int i, int start, unsigned int size)
{
	int j;

	if (i % 16 != 0)
	{
		j = i % 16;
		if (j % 2 != 0)
		{
			write(1, "  ", 2);
			j++;
		}
		else
			write(1, "    ", 4);
	}
	i -= start;
	j = 0;
	while (i < size && (j % 16 != 0 || j == 0))
	{
		if (*(addr + i) > 31 && *(addr + i) != 127)
			write(1, (addr + i), 1);
		else
			write(1, ".", 1);
		j++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				start;
	char			*c;
	uintptr_t		pointer;

	i = 0;
	while (i < size)
	{
		pointer = (uintptr_t)(addr + i);
		ft_print_pt(pointer, ft_digit_size(pointer));
		start = 0;
		while ((i % 16 != 0 || start == 0) && i < size)
		{
			start++;
			c = (char *)(addr + i);
			ft_print_hex(*c);
			if (i % 2 == 1)
				write(1, " ", 1);
			i++;
		}
		ft_print_str((char *)addr, i, start, size);
		write(1, "\n", 1);
	}
	return (addr);
}
