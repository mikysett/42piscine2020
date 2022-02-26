/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:46:06 by msessa            #+#    #+#             */
/*   Updated: 2020/12/08 20:46:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_init_op(int (*op_f[5])(int, int))
{
	*(op_f) = &ft_add;
	*(op_f + 1) = &ft_rm;
	*(op_f + 2) = &ft_multi;
	*(op_f + 3) = &ft_div;
	*(op_f + 4) = &ft_mod;
}

int		ft_valid_operator(char *op)
{
	if (ft_strlen(op) != 1)
		return (-1);
	if (*op == '+')
		return (0);
	else if (*op == '-')
		return (1);
	else if (*op == '*')
		return (2);
	else if (*op == '/')
		return (3);
	else if (*op == '%')
		return (4);
	else
		return (-1);
}

int		ft_err(int op_type, int nb2)
{
	if (op_type == -1)
	{
		ft_putstr("0\n");
		return (1);
	}
	else if (op_type == 3 && nb2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	else if (op_type == 4 && nb2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

void	do_op(int nb1, char *op, int nb2)
{
	int	op_type;
	int	(*op_f[5])(int, int);

	op_type = ft_valid_operator(op);
	if (ft_err(op_type, nb2))
		return ;
	ft_init_op(op_f);
	ft_putnbr((*op_f[op_type])(nb1, nb2));
	ft_putstr("\n");
}
