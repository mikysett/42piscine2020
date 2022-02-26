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

char	*ft_init_number(int argc, char **argv)
{
	if (argc > 3)
	{
		number_error();
		return (0);
	}
	if (argc == 2)
		return (argv[1]);
	else
		return (argv[2]);
}

char	*ft_init_dict_name(int argc, char **argv, char *std_dict)
{
	if (argc == 2)
		return (std_dict);
	else
		return (argv[1]);
}

int		main(int argc, char **argv)
{
	char	*number;
	char	*dict;
	char	std_dict[13];

	if (argc == 1)
	{
		ft_stdin();
		return (0);
	}
	else if ((number = ft_init_number(argc, argv)) != 0)
	{
		ft_strcpy(std_dict, "numbers.dict");
		dict = ft_init_dict_name(argc, argv, std_dict);
		ft_init_converter(number, dict);
	}
	return (0);
}
