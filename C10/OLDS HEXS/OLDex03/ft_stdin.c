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
#include "ft_hexdump.h"

int		ft_stdin(int c_option)
{
	char	buffer[BUFF_SIZE + 1];
	int		i;

	i = 0;
	while (read(STDIN_FILENO, (buffer + i), 1) > 0)
		i++;
	buffer[i] = '\0';
	if (i > 0)
		ft_print_memory(buffer, i, c_option);
	return (0);
}
