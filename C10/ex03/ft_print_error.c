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

#include "ft_hexdump.h"

void	ft_print_error(char *prog_name, char *file_name)
{
	ft_print_str(2, basename(prog_name));
	ft_print_str(2, ": ");
	ft_print_str(2, file_name);
	ft_print_str(2, ": ");
	ft_print_str(2, strerror(errno));
	ft_print_str(2, "\n");
}
