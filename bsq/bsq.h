/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:10:15 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 10:12:45 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 4000000

typedef struct s_labels	t_labels;
struct		s_labels
{
	char empty;
	char obst;
	char full;
};
typedef struct s_square	t_square;
struct		s_square
{
	int	row;
	int	col;
	int	size;
};
t_labels	g_labels;
char		**g_map;
int			**g_squares;
int			g_nb_lines;
int			g_nb_columns;

void		ft_handle_files(int nb_files, char **file_names);
void		ft_file_error(void);
void		ft_init_map(char *map_str);
int			ft_strlen(char *str);
int			ft_init_header(char *map_str);
void		ft_init_map(char *map_str);
void		ft_fill_map(t_square square);
int			ft_check_map(char *map_str);
void		ft_stdin(void);
void		ft_free_globals(void);
t_square	ft_find_square(void);

#endif
