/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:27:41 by msessa            #+#    #+#             */
/*   Updated: 2020/12/07 10:27:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc <= 1)
		ft_stdin();
	else
		while (i < argc)
		{
			if (!ft_display_file(argv[i]))
				ft_print_error(argv[i], argv[0]);
			i++;
		}
	return (0);
}
