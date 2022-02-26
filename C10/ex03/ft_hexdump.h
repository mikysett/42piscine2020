/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:15:29 by msessa            #+#    #+#             */
/*   Updated: 2020/12/16 08:17:33 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <fcntl.h>

int		g_c_opt;
char	g_cur_line[17];
char	g_prev_line[17];
int		g_pos_mem;
int		g_rep_lines;

void		ft_print_str(int output, char *str);
void		ft_print_last_line(void);
void		ft_print_error(char *prog_name, char *file_name);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
void		ft_handle_files(int argc, char **argv);
int			ft_handle_reads(int fd);
void		ft_print_pos_mem(long int nbr);
void		ft_print_16_hex(void);
void		ft_print_line(void);

#endif
