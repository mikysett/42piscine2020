/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:38:25 by msessa            #+#    #+#             */
/*   Updated: 2020/11/27 09:38:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalphanum(char str)
{
	if ((str >= 'A' && str <= 'Z')
		|| (str >= 'a' && str <= 'z')
		|| (str >= '0' && str <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z')
			|| (*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			if (i == 0 || !ft_isalphanum(*(str + i - 1)))
			{
				if (*(str + i) >= 'a' && *(str + i) <= 'z')
					*(str + i) -= 32;
			}
			else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
				*(str + i) += 32;
		}
		i++;
	}
	return (str);
}
