/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:16:58 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:17:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_read_err(char *prog_name, char *file_name)
{
	ft_print_str(2, basename(prog_name));
	ft_print_str(2, ": ");
	ft_print_str(2, file_name);
	ft_print_str(2, ": ");
	ft_print_str(2, "Bad file descriptor\n");
}

void	ft_handle_files(int argc, char **argv)
{
	int		i;
	int		fd;
	int		err_bad_descriptor;

	i = 1 + g_c_opt;
	err_bad_descriptor = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_print_error(argv[0], argv[i]);
		else
		{
			err_bad_descriptor = 0;
			ft_handle_reads(fd);
			close(fd);
		}
		i++;
	}
	if (g_pos_mem > 0)
		ft_print_last_line();
	if (err_bad_descriptor)
		ft_print_read_err(argv[0], argv[i - 1]);
}
