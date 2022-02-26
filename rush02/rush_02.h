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
# include <fcntl.h>
# define BUFF_SIZE 100

typedef struct s_list	t_list;
struct	s_list
{
	char *key;
	char *value;
};

void	ft_stdin(void);
void	ft_init_converter(char *number, char *dict);
int		ft_is_number(char c);
int		ft_is_space(char c);
int		ft_is_printable(char c);
char	*ft_valid_number(char *number);
t_list	**ft_valid_dict(char *dict_name);
char	*ft_strcpy(char *dest, char *src);
int		ft_semantic_check(t_list *dict[], int nb_keys);
int		ft_is_value_empty(char *value);
t_list	**ft_create_dict(char *dict_str, int nb_keys);
int		ft_set_keys(char *dict_str, t_list **dict_arr);
int		dict_valid_syntax(char *dict);
void	number_error(void);
void	dict_error(void);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_printer(char *number, t_list **dict_arr);
void	ft_p_digit1(char *number, t_list **dict_arr, int pos, int len_nbr);
void	ft_p_digit2(char *number, t_list **dict_arr, int pos);
void	ft_p_digit3(char *number, t_list **dict_arr, int pos);
void	ft_print_tens(char *number, t_list **dict_arr, int pos);
void	ft_p_bigs(char *number, t_list **dict_arr, int pos, int len_nbr);
int		ft_all_zeros(char *number, int pos);
void	ft_sort_dict(t_list **dict_arr);
int		ft_is_stdbig(char *key, int pos, int len_nbr);
int		ft_check_exact_match(char *number, t_list **dict_arr);
int		ft_strcmp(char *s1, char *s2);
int		ft_number_too_big(t_list **dict_arr, char *number);
int		ft_is_magnitude(char *key);
int		ft_check_hifen(char *number, int pos, int len_nbr);
int		ft_check_and(char *number, int pos, int len_nbr);
int		ft_check_big(char *number, int pos, int len_nbr);
int		ft_check_comma(char *number, int pos, int len_nbr);
int		ft_all_zeros_forward(char *number, int pos, int len_nbr);
void	ft_free_dict_arr(t_list **dict_arr);

#endif
