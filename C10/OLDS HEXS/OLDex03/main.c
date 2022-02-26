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

char		*ft_init_str(int tot_size)
{
	char *str;

	str = 0;
	if (tot_size > 0)
	{
		str = malloc(sizeof(char) * (tot_size + 1));
		str[0] = '\0';
	}
	return (str);
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
	int			i;
	long int	tot_size;
	char		*str;
	int			*f_size;
	int			c_option;

	i = 0;
	c_option = set_c_option(argc, argv);
	if (argc == 1 || (argc == 2 && c_option == 1))
		return (ft_stdin(c_option));
	argv = ft_set_args(&argc, argv, c_option);
	f_size = malloc(sizeof(int) * (argc));
	tot_size = set_tot_size(argc, argv, f_size);
	str = ft_init_str(tot_size);
	while (i < argc)
	{
		if (!ft_read_file(argv[i], str, i, f_size))
			ft_print_error(argv, argc, i, c_option);
		i++;
	}
	ft_print_memory(str, tot_size, c_option);
	return (0);
}
