/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:53:22 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 18:53:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_stdin_err(void)
{
	ft_putstr("ENTRY TOO BIG, SORRY MAN\n");
	return (0);
}

void	ft_stdin_nb_check(char *typed_number, t_list **dict_arr)
{
	char *number;

	if (!(number = ft_valid_number(typed_number)))
		number_error();
	else
		ft_printer(number, dict_arr);
}

void	ft_stdin(void)
{
	t_list	**dict_arr;
	char	typed_number[BUFF_SIZE];
	int		i;

	dict_arr = ft_valid_dict("numbers.dict");
	if (!dict_arr)
		return (dict_error());
	i = 0;
	while (read(STDIN_FILENO, typed_number + i++, 1) > 0)
	{
		if (i > BUFF_SIZE)
			i = ft_stdin_err();
		else if (typed_number[i - 1] == '\n')
		{
			typed_number[i - 1] = '\0';
			ft_stdin_nb_check(typed_number, dict_arr);
			i = 0;
		}
	}
	ft_free_dict_arr(dict_arr);
}
