/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:26:31 by msessa            #+#    #+#             */
/*   Updated: 2020/12/02 18:04:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			write(1, arg, 1);
			arg++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
