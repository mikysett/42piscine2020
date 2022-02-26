/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:04:07 by msessa            #+#    #+#             */
/*   Updated: 2020/11/29 19:06:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n < 1)
		return (0);
	while (*s1++ == *s2++ && *(s1 - 1) && *(s2 - 1) && --n > 0)
		continue;
	return (*(s1 - 1) - *(s2 - 1));
}
