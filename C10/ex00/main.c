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

#include "ft_display_file.h"

int		main(int argc, char **argv)
{
	if (argc <= 1)
		ft_print_str(2, "File name missing.\n");
	else if (argc > 2)
		ft_print_str(2, "Too many arguments.\n");
	else if (!ft_display_file(argv[1]))
		ft_print_str(2, "Cannot read file.\n");
	return (0);
}
