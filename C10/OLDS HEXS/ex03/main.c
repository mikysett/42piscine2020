/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:04:49 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 11:04:52 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_hexdump.h"

int			set_c_option(int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
		return (1);
	return (0);
}

char		**ft_set_args(int *argc, char **argv, int c_option)
{
	(*argc)--;
	argv++;
	if (c_option)
	{
		(*argc)--;
		argv++;
	}
	return (argv);
}

int			main(int argc, char **argv)
{
	char	*prog_name;
	int		c_option;

	c_option = set_c_option(argc, argv);
	if (argc == 1 || (argc == 2 && c_option == 1))
		return (ft_stdin(c_option));
	prog_name = argv[0];
	argv = ft_set_args(&argc, argv, c_option);
	ft_print_memory(argc, argv, prog_name, c_option);
	return (0);
}
