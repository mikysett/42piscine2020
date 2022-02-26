/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_last_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:18:15 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:18:18 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_last_line(void)
{
	if (g_rep_lines != 0)
	{
		write(1, "*\n", 2);
		g_rep_lines = 0;
	}
	if (*g_cur_line != '\0')
		ft_print_line();
	ft_print_pos_mem(g_pos_mem);
	write(1, "\n", 1);
}
