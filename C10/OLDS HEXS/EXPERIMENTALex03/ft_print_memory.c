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
#include "ft_hexdump.h"

void	ft_print_spaces(int position, int c_op)
{
	int max;

	max = 16;
	if (position < 8 && c_op)
		write(1, " ", 1);
	while (position < max)
	{
		write(1, "  ", 2);
		if (position + 1 < 16)
			write(1, " ", 1);
		position++;
	}
}

void	ft_p_hex_str(char *addr, unsigned int i, int start, unsigned int size)
{
	int j;

	i -= start;
	write(1, "  |", 3);
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
	write(1, "|", 1);
}

void	ft_p_last_hex(unsigned int i, long int first_ptr, void *addr, int c_op)
{
	if (i != 0)
	{
		ft_putnbr_hex((long int)(addr + i) - first_ptr, c_op);
		write(1, "\n", 1);
	}
}

int		ft_p_16_hex(void *addr, unsigned int *i, unsigned int size, int c_op)
{
	int start;

	start = 0;
	while ((*i % 16 != 0 || start == 0) && *i < size)
	{
		start++;
		ft_print_hex(*(char *)(addr + *i));
		if ((*i + 1) % 16 != 0)
		{
			write(1, " ", 1);
			if ((*i + 1) % 8 == 0 && c_op)
				write(1, " ", 1);
		}
		(*i)++;
	}
	return (start);
}

void	ft_print_memory(void *addr, unsigned int size, int c_option)
{
	unsigned int	i;
	int				start;
	long int		first_ptr;

	i = 0;
	first_ptr = (long int)addr;
	while (i < size)
	{
		ft_putnbr_hex((long int)(addr + i) - first_ptr, c_option);
		write(1, " ", 1);
		if (c_option)
			write(1, " ", 1);
		start = ft_p_16_hex(addr, &i, size, c_option);
		ft_print_spaces(start, c_option);
		if (c_option)
			ft_p_hex_str((char *)addr, i, start, size);
		write(1, "\n", 1);
		if (i != size)
			i += ft_skip_l((char *)addr, i, 0, 0);
	}
	ft_p_last_hex(i, first_ptr, addr, c_option);
}
