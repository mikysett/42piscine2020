/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:15:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 20:15:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# define BUFF_SIZE 29000

void		ft_print_str(int output, char *str);
void		ft_write_file_name(char *name);
void		ft_print_error(char **argv, int nb_arg, int sel_ar, int c_opt);
int			ft_stdin(int c_option);
int			ft_read_file(char *file, char *str, int f_sel, int *f_size);
int			ft_file_size(char *filename);
long int	set_tot_size(int argc, char **argv, int *f_size);
void		ft_print_memory(void *addr, unsigned int size, int c_option);
char		*ft_strcat(char *dest, char *src);
void		ft_putnbr_hex(long int nbr, int c_op);
int			ft_digit_size(int n);
void		ft_print_hex(char c);
int			ft_skip_l(char *addr, unsigned int line1, int nb_lines, int count);
int			ft_strcmp(char *s1, char *s2);

#endif
