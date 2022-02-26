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

#include "ft_hexdump.h"

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

long int		set_tot_size(int argc, char **argv, int *file_sizes)
{
	int			i;
	long int	file_size;
	long int	tot_size;

	i = 0;
	tot_size = 0;
	while (i < argc)
	{
		file_size = ft_file_size(argv[i]);
		if (file_size != -1)
		{
			tot_size += file_size;
			file_sizes[i] = file_size;
		}
		else
			file_sizes[i] = 0;
		i++;
	}
	return (tot_size);
}

long int		set_max_size(int argc, char **argv)
{
	int			i;
	long int	file_size;
	long int	max_size;

	i = 0;
	max_size = 0;
	while (i < argc)
	{
		file_size = ft_file_size(argv[i]);
		if (file_size > max_size)
			max_size = file_size;
		i++;
	}
	return (max_size + 17);
}
