/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:20:23 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 17:21:20 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_set_file_size(char *f_name)
{
	int		fd;
	int		f_size;
	int		read_res;
	char	buff;

	f_size = 0;
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read_res = read(fd, &buff, 1)) > 0)
		f_size++;
	close(fd);
	return (f_size);
}

int		ft_copy_file(char *f_name, char *file_str, int f_size)
{
	int		fd;
	int		read_res;

	if ((fd = open(f_name, O_RDONLY)) == -1
		|| (read_res = read(fd, file_str, f_size)) < 0)
	{
		ft_file_error();
		return (0);
	}
	close(fd);
	file_str[f_size] = '\0';
	return (1);
}

void	ft_handle_files(int nb_files, char **file_names)
{
	int		i;
	int		f_size;
	char	*file_str;

	i = 0;
	while (i < nb_files)
	{
		f_size = ft_set_file_size(file_names[i]);
		if (f_size < 7)
			ft_file_error();
		else if ((file_str = malloc(sizeof(char) * (f_size + 1))))
		{
			if (ft_copy_file(file_names[i], file_str, f_size))
				ft_init_map(file_str);
			free(file_str);
		}
		if (nb_files > 1)
			write(1, "\n", 1);
		i++;
	}
}
