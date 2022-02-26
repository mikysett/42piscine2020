/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:24:51 by msessa            #+#    #+#             */
/*   Updated: 2020/12/04 12:24:55 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset);
int		ft_nb_strs(char *str, char *charset);
void	ft_set_strs_size(int *strs_size, char *str, char *charset);
void	ft_cpy_strs(char **strs, char *str, char *charset);
char	**ft_split(char *str, char *charset);

int		is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_nb_strs(char *str, char *charset)
{
	int i;
	int nb_strs;

	i = 0;
	nb_strs = 0;
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (is_sep(str[i], charset) && str[i + 1] != '\0'
			&& !is_sep(str[i + 1], charset))
			nb_strs++;
		i++;
	}
	if (nb_strs != 0)
		return (nb_strs + 2);
	return (nb_strs + 1);
}

void	ft_set_strs_size(int *strs_size, char *str, char *charset)
{
	int		str_sel;
	int		str_sel_size;
	int		i;

	i = 0;
	str_sel = 0;
	str_sel_size = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
			str_sel_size++;
		else if (str_sel_size != 0)
		{
			strs_size[str_sel] = str_sel_size + 1;
			str_sel++;
			str_sel_size = 0;
		}
		i++;
	}
	if (str_sel_size != 0)
		strs_size[str_sel++] = str_sel_size + 1;
	strs_size[str_sel] = 0;
}

void	ft_cpy_strs(char **strs, char *str, char *charset)
{
	int		str_sel;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_sel = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
			strs[str_sel][j++] = str[i];
		else if (j != 0)
		{
			strs[str_sel][j] = '\0';
			str_sel++;
			j = 0;
		}
		i++;
	}
	if (j != 0)
		strs[str_sel++][j] = '\0';
	strs[str_sel] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		nb_strs;
	int		*strs_size;
	char	**res;
	int		i;

	nb_strs = ft_nb_strs(str, charset);
	strs_size = malloc(sizeof(int) * (nb_strs));
	if (!strs_size)
		return (0);
	res = malloc(sizeof(char *) * (nb_strs));
	if (!res)
		return (0);
	ft_set_strs_size(strs_size, str, charset);
	i = 0;
	while (i < nb_strs)
	{
		res[i] = malloc(sizeof(char) * strs_size[i]);
		if (!res[i])
			return (0);
		i++;
	}
	ft_cpy_strs(res, str, charset);
	return (res);
}
