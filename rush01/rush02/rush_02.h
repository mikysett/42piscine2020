/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 09:17:20 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 09:17:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_list
{
	char *key;
	char *value;
}				t_list;

void	ft_init_converter(char *number, char *dict);
int		ft_is_number(char c);
int		ft_is_space(char c);
int		ft_is_printable(char c);
char	*ft_valid_number(char *number);
int		ft_valid_dict(char *dict);
char	*ft_strcpy(char *dest, char *src);
int		ft_semantic_check(t_list *dict[], int nb_keys);
int		ft_is_value_empty(char *value);
t_list	**ft_create_dict(char *dict, int nb_keys);

#endif
