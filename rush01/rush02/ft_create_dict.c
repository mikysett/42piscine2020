#include "rush_02.h"

char	*ft_get_key(char *dict, int start, int key_size)
{
	char *key;
	int i;

	i = 0;
	key = malloc(sizeof(char) * key_size + 1);
	if(!key)
		return (0);
	while (i < key_size)
	{
		key[i] = dict[start + i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

int		ft_set_keys(char *dict, t_list **dict_arr)
{
	int i;
	int key_size;
	int k;

	i = 0;
	k = 0;
	while (dict[i]) 
	{
		key_size = 0;
		while (dict[i] == '\n')
			i++;
		while (ft_is_number(dict[i + key_size]))
			key_size++;
		dict_arr[k]->key = ft_get_key(dict, i, key_size);
		if (!(dict_arr[k]->key))
			return (0);
		k++;
		i += key_size;
		while (dict[i] != '\n')
			i++;
	}
	return (1);
}

char	*ft_get_value(char *dict, int start, int val_size)
{
	char *value;
	int i;
	i = 0;
	value = malloc(sizeof(char) * val_size + 1);
	if (!value)
		return (0);
	while (i < val_size)
	{
		value[i] = dict[start + i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

int		ft_set_values(char *dict, t_list **dict_arr)
{
	int i;
	int val_size;
	int k;

	i = 0;
	k = 0;
	while (dict[i]) 
	{
		while (dict[i] != ':')
			i++;
		i++;
		while (ft_is_space(dict[i]))
			i++;
		val_size = 0;
		while (dict[i] != '\n' && !ft_is_value_empty(dict + i))
			val_size++;
		dict_arr[k]->value = ft_get_value(dict, i, val_size);
		if (!(dict_arr[k]->value))
			return (0);
		k++;
		i += val_size;
		while (ft_is_space(dict[i]) || dict[i] == '\n')
			i++;
	}
	return (1);
}

t_list	**ft_create_dict(char *dict, int nb_keys)
{
	t_list **dict_arr;
	int k;

	dict_arr = malloc(sizeof(t_list *) * (nb_keys + 1));
	if (!dict_arr)
		return (0);
	k = 0;
	while (k < nb_keys)
	{
		dict_arr[k] = malloc(sizeof(t_list));
		if (!dict_arr[k])
			return (0);
		k++;
	}
	dict_arr[k] = 0;
	if(!ft_set_keys(dict, dict_arr) || !ft_set_values(dict, dict_arr))
		return (0);
	return (dict_arr);
}

