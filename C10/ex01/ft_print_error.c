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
#include <errno.h>
#include <libgen.h>
#include "ft_cat.h"

void	ft_print_error(char *filename, char *prog_name)
{
	ft_print_str(2, basename(prog_name));
	ft_print_str(2, ": ");
	ft_print_str(2, filename);
	ft_print_str(2, ": ");
	ft_print_str(2, strerror(errno));
	ft_print_str(2, "\n");
}
