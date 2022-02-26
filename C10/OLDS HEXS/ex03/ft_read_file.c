/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:14:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 17:14:33 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_hexdump.h"

int		print_file(int file, char *str, int f_sel, int *f_size)
{
	int		read_result;
	char	*buff;

	buff = malloc(sizeof(char) * (f_size[f_sel] + 1));
	if (!buff)
		return (0);
	read_result = read(file, buff, f_size[f_sel]);
	if (read_result == -1)
	{
		free(buff);
		return (0);
	}
	buff[f_size[f_sel]] = '\0';
	ft_strcat(str, buff);
	free(buff);
	return (1);
}

int		ft_read_file(char *file, char *str, int f_sel, int *f_size)
{
	int file_d;
	int print_success;

	file_d = open(file, O_RDONLY);
	if (file_d == -1)
		return (0);
	print_success = print_file(file_d, str, f_sel, f_size);
	close(file_d);
	return (print_success);
}
