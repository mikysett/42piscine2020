/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:20:52 by msessa            #+#    #+#             */
/*   Updated: 2020/12/02 18:05:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*name;
	int		nb_arg;

	name = argv[0];
	nb_arg = argc;
	while (*name)
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
	return (0);
}
