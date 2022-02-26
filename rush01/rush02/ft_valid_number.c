/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:11:09 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 13:11:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_valid_number(char *number)
{
	int start_of_nbr;
	int i;

	start_of_nbr = -1;
	i = 0;
	while (*number && ft_is_space(*number))
		number++;
	if (!(*number) || *number == '-')
		return (0);
	if (*number == '+')
		number++;
	while (number[i] != '\0')
	{
		if (!ft_is_number(number[i]))
			return (0);
		if (start_of_nbr == -1
			&& (number[i] != '0' || number[i + 1] == '\0'))
			start_of_nbr = i;
		i++;
	}
	return (number + start_of_nbr);
}
