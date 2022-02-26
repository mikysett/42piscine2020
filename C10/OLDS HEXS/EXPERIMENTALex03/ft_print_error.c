/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:11:23 by msessa            #+#    #+#             */
/*   Updated: 2020/12/07 19:11:32 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include "ft_hexdump.h"

void	ft_print_error(char **argv, int nb_arg, int sel_ar, int c_opt)
{
	char buff[1];
	char *p_name;

	if (c_opt)
		p_name = *(argv - 2);
	else
		p_name = *(argv - 1);
	if (errno == 2)
	{
		ft_print_str(2, basename(p_name));
		ft_print_str(2, ": ");
		ft_print_str(2, argv[sel_ar]);
		ft_print_str(2, ": ");
		ft_print_str(2, strerror(errno));
		ft_print_str(2, "\n");
	}
	if (nb_arg == (sel_ar + 1) && read(22, buff, 1) == -1)
	{
		ft_print_str(2, basename(p_name));
		ft_print_str(2, ": ");
		ft_print_str(2, argv[sel_ar]);
		ft_print_str(2, ": ");
		ft_print_str(2, strerror(errno));
		ft_print_str(2, "\n");
	}
}
