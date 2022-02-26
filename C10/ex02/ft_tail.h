/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:08:34 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 20:10:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define BUFF_SIZE 29000

int		ft_atoi(char *str);
void	ft_write_file_name(char *name);
void	ft_print_error(char *filename, char *prog_name);
void	ft_stdin(int tail);
int		ft_tail(char *filename, int tail);
void	ft_print_str(int output, char *str);

#endif
