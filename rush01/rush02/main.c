/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 09:17:08 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 09:17:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		main(int argc, char **argv)
{
	char	*number;
	char	*dict;
	char	std_dict[13];

	ft_strcpy(std_dict, "numbers.dict");
	if (argc == 2)
	{
		dict = std_dict;
		number = argv[1];
	}
	else
	{
		dict = argv[1];
		number = argv[2];
	}
	ft_init_converter(number, dict);
	return (0);
}
