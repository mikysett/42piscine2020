/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:19:54 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:19:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_set_g_c_option(int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
		g_c_opt = 1;
	else
		g_c_opt = 0;
}

void	ft_init_globals(void)
{
	g_c_opt = 0;
	g_cur_line[0] = '\0';
	g_prev_line[0] = '\0';
	g_pos_mem = 0;
	g_rep_lines = 0;
}

int		main(int argc, char **argv)
{
	ft_init_globals();
	ft_set_g_c_option(argc, argv);
	if (argc <= 1 || (argc == 2 && g_c_opt == 1))
	{
		ft_handle_reads(STDIN_FILENO);
		if (g_pos_mem > 0)
			ft_print_last_line();
	}
	else
	{
		ft_handle_files(argc, argv);
	}
	return (0);
}
