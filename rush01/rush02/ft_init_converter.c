/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 10:11:38 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 10:11:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	number_error(void)
{
	write(1, "Error\n", 6);
}

void	dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

void	ft_init_converter(char *number, char *dict)
{
	if (!(number = ft_valid_number(number)))
		return (number_error());
	if (!ft_valid_dict(dict))
		return (dict_error());

	// Create the dictionary in memory
	// Malloc used, checks to be made

	// Make Semantic check
	// Possibility to return error AND freeing dictionary

	// Print the number
}
