/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:11:08 by msessa            #+#    #+#             */
/*   Updated: 2020/12/07 19:11:13 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_cat.h"

void	ft_stdin(void)
{
	char	buffer[BUFF_SIZE + 1];
	int		str_size;

	while ((str_size = read(STDIN_FILENO, buffer, BUFF_SIZE)))
	{
		buffer[str_size] = '\0';
		ft_print_str(1, buffer);
	}
}
