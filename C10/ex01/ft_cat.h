/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:04:02 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 20:04:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# define BUFF_SIZE 29000

int		ft_display_file(char *file);
void	ft_print_str(int output, char *str);
int		print_file(int file, int size);
void	ft_print_error(char *filename, char *prog_name);
void	ft_stdin(void);

#endif
