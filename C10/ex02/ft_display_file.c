/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:27:16 by msessa            #+#    #+#             */
/*   Updated: 2020/12/07 10:27:29 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		print_file(int file)
{
	int		read_result;
	char	buffer[1];

	read_result = read(file, buffer, 1);
	while (read_result > 0)
	{
		write(1, buffer, 1);
		read_result = read(file, buffer, 1);
	}
	if (read_result == -1)
		return (0);
	return (1);
}

int		ft_display_file(char *file)
{
	int file_d;
	int print_success;

	file_d = open(file, O_RDONLY);
	if (file_d == -1)
		return (0);
	print_success = print_file(file_d);
	close(file_d);
	return (print_success);
}
