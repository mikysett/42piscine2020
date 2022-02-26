/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:18:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:18:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_spaces(int position)
{
	if (position < 8 && g_c_opt)
		write(1, " ", 1);
	while (position < 16)
	{
		write(1, "  ", 2);
		if (position + 1 < 16)
			write(1, " ", 1);
		position++;
	}
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

void	ft_print_hex_str(void)
{
	int i;

	i = 0;
	write(1, "  |", 3);
	while (g_cur_line[i])
	{
		if (g_cur_line[i] > 31 && g_cur_line[i] != 127)
			write(1, (g_cur_line + i), 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	ft_print_16_hex(void)
{
	int i;

	i = 0;
	while (g_cur_line[i])
	{
		ft_print_hex(g_cur_line[i]);
		if ((i + 1) % 16 != 0)
		{
			write(1, " ", 1);
			if ((i + 1) % 8 == 0 && g_c_opt)
				write(1, " ", 1);
		}
		i++;
	}
	if (i < 16)
		ft_print_spaces(i);
}

void	ft_print_line(void)
{
	if (g_pos_mem % 16 == 0)
		ft_print_pos_mem(g_pos_mem - 16);
	else
		ft_print_pos_mem(g_pos_mem - (g_pos_mem % 16));
	write(1, " ", 1);
	if (g_c_opt)
		write(1, " ", 1);
	ft_print_16_hex();
	if (g_c_opt)
		ft_print_hex_str();
	write(1, "\n", 1);
}
