/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 10:34:14 by julcarva          #+#    #+#             */
/*   Updated: 2020/11/28 18:12:37 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char str);
void	rush(int x, int y);

int		main(void)
{
	rush(5, 5);
	ft_putchar('\n');
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	return (0);
}
