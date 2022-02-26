/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_reads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:17:10 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:17:14 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_add_char(char *g_cur_line, char c)
{
	while (*g_cur_line)
		g_cur_line++;
	*g_cur_line = c;
	*(g_cur_line + 1) = '\0';
}

void	ft_handle_g_rep_lines(void)
{
	if (ft_strcmp(g_cur_line, g_prev_line) == 0)
		g_rep_lines++;
	else if (g_rep_lines != 0)
	{
		write(1, "*\n", 2);
		g_rep_lines = 0;
	}
}

int		ft_handle_reads(int fd)
{
	int		read_res;
	char	buff;

	while ((read_res = read(fd, &buff, 1)) > 0)
	{
		g_pos_mem++;
		ft_add_char(g_cur_line, buff);
		if (g_pos_mem % 16 == 0)
		{
			ft_handle_g_rep_lines();
			if (!g_rep_lines)
			{
				ft_print_line();
				ft_strcpy(g_prev_line, g_cur_line);
			}
			ft_strcpy(g_cur_line, "");
		}
	}
	if (read_res == -1)
		return (0);
	return (1);
}
