/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:38:35 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 20:38:39 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

int		ft_atoi(char *str);
void	do_op(int nb1, char *op, int nb2);
int		ft_strlen(char *str);
void	ft_init_op(int(*op_f[5])(int, int));
int		ft_add(int nb1, int nb2);
int		ft_rm(int nb1, int nb2);
int		ft_multi(int nb1, int nb2);
int		ft_div(int nb1, int nb2);
int		ft_mod(int nb1, int nb2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif
