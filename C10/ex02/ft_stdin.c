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
#include <stdlib.h>
#include "ft_tail.h"

void	ft_print_stdin(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_add_c_tail(char *str_tail, int tail, char c)
{
	int i;

	i = 0;
	while (i < tail)
	{
		str_tail[i] = str_tail[i + 1];
		i++;
	}
	str_tail[i] = c;
}

void	ft_stdin(int tail)
{
	char	c;
	char	str_tail[tail + 1];
	int		length;
	int		read_res;

	read_res = 1;
	length = 0;
	if (tail <= 0)
		return ;
	while (read_res > 0)
	{
		read_res = read(STDIN_FILENO, &c, 1);
		if (length < tail)
			str_tail[length] = c;
		else
			ft_add_c_tail(str_tail, tail, c);
		length++;
	}
	if (length < tail)
		str_tail[length - 1] = '\0';
	else
		str_tail[tail] = '\0';
	if (length > 1)
		ft_print_stdin(str_tail);
}
