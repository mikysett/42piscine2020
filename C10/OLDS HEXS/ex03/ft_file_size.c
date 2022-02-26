/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:08:52 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 12:08:59 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

long int		ft_file_size(char *filename)
{
	int				file_d;
	long int		read_result;
	long int		file_size;
	char			buffer[1];

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
