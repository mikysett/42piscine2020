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

void	ft_init_buffer(char *str, int buff_size)
{
	char *buff;

	buff = malloc(sizeof(char) * (buff_size + 1));
	if (!buff)
		return (0);
	ft_strcpy(buff, str);
}

int		ft_save_file(char *file, char *str, int max_size)
{
	int		file_d;
	int		print_success;
	int		file_size;
	int		start_str_size;
	char	buffer[max_size];

	file_d = open(file, O_RDONLY);
	if (file_d == -1)
		return (0);
	start_str_size = ft_strlen(str);
	file_size = read(file_d, str, max_size);
	str[file_size + start_str_size] = '\0';
	print_success = print_file(file_d, str, f_sel);
	close(file_d);
	return (print_success);
}
