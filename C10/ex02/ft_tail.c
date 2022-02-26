/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:41:04 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 08:41:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		print_file_tail(int file, int file_size, int tail)
{
	int		read_result;
	int		position_sel;
	char	buffer[1];

	position_sel = 0;
	read_result = read(file, buffer, 1);
	while (read_result > 0)
	{
		if (file_size - position_sel <= tail)
		{
			write(1, buffer, 1);
		}
		read_result = read(file, buffer, 1);
		position_sel++;
	}
	if (read_result == -1)
		return (0);
	return (1);
}

int		ft_file_size(char *filename)
{
	int		file_d;
	int		read_result;
	int		file_size;
	char	buffer[1];

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (-1);
	file_size = 0;
	read_result = read(file_d, buffer, 1);
	while (read_result > 0)
	{
		read_result = read(file_d, buffer, 1);
		file_size++;
	}
	if (read_result == -1)
	{
		close(file_d);
		return (-1);
	}
	close(file_d);
	return (file_size);
}

int		ft_tail(char *filename, int tail)
{
	int file_d;
	int file_size;

	if (tail < 0)
		return (0);
	if ((file_size = ft_file_size(filename)) == -1)
		return (0);
	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	if (file_size == -1)
	{
		close(file_d);
		return (0);
	}
	if (!print_file_tail(file_d, file_size, tail))
	{
		close(file_d);
		return (0);
	}
	close(file_d);
	return (1);
}
