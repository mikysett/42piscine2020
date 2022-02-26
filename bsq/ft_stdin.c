/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:15:22 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 17:15:25 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_stdin(void)
{
	char	buff[BUFF_SIZE];
	int		read_res;

	while ((read_res = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0)
	{
		if (read_res > BUFF_SIZE)
			ft_file_error();
		else
		{
			buff[read_res] = '\0';
			ft_init_map(buff);
		}
	}
}
