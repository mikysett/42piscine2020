/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:19:59 by msessa            #+#    #+#             */
/*   Updated: 2020/12/07 20:26:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "ft_tail.h"

int		ft_file_exists(char *filename)
{
	int file_d;

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	close(file_d);
	return (1);
}

void	ft_handle_file_name(int argc, int pos_sel, char **argv)
{
	int previous_exists;
	int i;

	previous_exists = 0;
	i = 3;
	while (i < pos_sel)
	{
		if (ft_file_exists(argv[i]))
		{
			previous_exists = 1;
			break ;
		}
		i++;
	}
	if (argc > 4 && ft_file_exists(argv[pos_sel]))
	{
		if (previous_exists)
			write(1, "\n", 1);
		ft_write_file_name(argv[pos_sel]);
	}
}

int		ft_invalid_offset(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 3)
		return (1);
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] < '0' || argv[2][i] > '9')
		{
			ft_print_str(2, basename(argv[0]));
			ft_print_str(2, ": illegal offset -- ");
			ft_print_str(2, argv[2]);
			ft_print_str(2, "\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int tail;
	int i;

	i = 3;
	if (ft_invalid_offset(argc, argv))
		return (0);
	else if (argc == 3)
		ft_stdin(ft_atoi(argv[2]));
	else
	{
		tail = ft_atoi(argv[2]);
		while (i < argc)
		{
			ft_handle_file_name(argc, i, argv);
			if (!ft_tail(argv[i], tail))
				ft_print_error(argv[i], argv[0]);
			i++;
		}
	}
	return (0);
}
