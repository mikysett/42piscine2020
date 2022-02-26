// MAINS

// EX 06
t_list	*ft_create_elem(void *data)
{


	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}

t_list	*ft_list_push_strs(int size, char **strs)
{



	int		i;
	t_list	*begin;
	t_list	*tracker;

	i = size - 1;
	begin = 0;
	while (i >= 0)
	{
		if (begin)
		{
			tracker->next = ft_create_elem(strs[i]);
			tracker = tracker->next;
		}
		else
		{
			begin = ft_create_elem(strs[i]);
			tracker = begin;
		}
		i--;
	}
	return (begin);
}

void	ft_print_list(t_list *begin_list)
{


	while (begin_list)
	{
		printf("%s\n", (begin_list)->data);
		begin_list = (begin_list)->next;
	}
}

int		main(int argc, char **argv)
{
	t_list *begin;

	begin = ft_list_push_strs(argc, argv);
	ft_print_list(begin);
	ft_list_clear(begin, &free_fct);
	printf("START TO REPRINT\n");
	ft_print_list(begin);

	return (0);
}



// EX 07
t_list	*ft_create_elem(void *data)
{


	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}

t_list	*ft_list_push_strs(int size, char **strs)
{



	int		i;
	t_list	*begin;
	t_list	*tracker;

	i = size - 1;
	begin = 0;
	while (i >= 0)
	{
		if (begin)
		{
			tracker->next = ft_create_elem(strs[i]);
			tracker = tracker->next;
		}
		else
		{
			begin = ft_create_elem(strs[i]);
			tracker = begin;
		}
		i--;
	}
	return (begin);
}

void	ft_print_list(t_list *begin_list)
{


	while (begin_list)
	{
		printf("%s\n", (begin_list)->data);
		begin_list = (begin_list)->next;
	}
}

int		main(int argc, char **argv)
{
	t_list *begin;
	int		eln;

	eln = 8;
	printf("START READING AT POS: %d\n", eln);
	begin = ft_list_push_strs(argc, argv);
	ft_print_list(begin);
	begin = ft_list_at(begin, eln);
	printf("START TO REPRINT\n");
	ft_print_list(begin);

	return (0);
}

// MAIN 08

int		main(int argc, char **argv)
{
	t_list **begin;
	t_list *first;
	t_list f_el;
	char first_str[5] = "qqqq\n";

	f_el.data = &first_str;
	f_el.next = 0;
	first = &f_el;
	begin = &first;
	*begin = ft_list_push_strs(argc, argv);
	ft_print_list(*begin);
	ft_list_reverse3(begin);
	printf("\nSTART TO REPRINT\n");
	ft_print_list(*begin);

	return (0);
}


// EX 14








t_list	*ft_create_elem(void *data)
{


	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}

t_list	*ft_list_push_strs(int size, char **strs)
{



	int		i;
	t_list	*begin;
	t_list	*tracker;

	i = size - 1;
	begin = 0;
	while (i >= 0)
	{
		if (begin)
		{
			tracker->next = ft_create_elem(strs[i]);
			tracker = tracker->next;
		}
		else
		{
			begin = ft_create_elem(strs[i]);
			tracker = begin;
		}
		i--;
	}
	return (begin);
}

void	ft_print_list(t_list *begin_list)
{


	while (begin_list)
	{
		printf("%s\n", (begin_list)->data);
		begin_list = (begin_list)->next;
	}
}

int		main(int argc, char **argv)
{
	t_list *begin;
	int		i;

	begin = ft_list_push_strs(argc - 1, argv + 1);
	printf("THE LIST WE GOT\n");
	ft_print_list(begin);
	ft_list_sort(&begin, &strcmp);
	printf("\n\nSTART TO REPRINT\n");
	ft_print_list(begin);

	return (0);
}


// EX 15

t_list	*ft_create_elem(void *data)
{


	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}

t_list	*ft_list_push_strs(int size, char **strs)
{



	int		i;
	t_list	*begin;
	t_list	*tracker;

	i = size - 1;
	begin = 0;
	while (i >= 0)
	{
		if (begin)
		{
			tracker->next = ft_create_elem(strs[i]);
			tracker = tracker->next;
		}
		else
		{
			begin = ft_create_elem(strs[i]);
			tracker = begin;
		}
		i--;
	}
	return (begin);
}

void	ft_print_list(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		printf("%s\n", (char *)(begin_list)->data);
		begin_list = (begin_list)->next;
		i++;
		if (i > 50)
		{
			printf("INFINITE LOOP?!?!?!?\n");
			break;
		}
	}
}

int		main(int argc, char **argv)
{
	t_list **begin;
	t_list *first;
	t_list f_el;
	char first_str[5] = "qqqq\n";

	f_el.data = &first_str;
	f_el.next = 0;
	first = &f_el;
	begin = &first;
	*begin = ft_list_push_strs(argc, argv);
	ft_print_list(*begin);
	ft_list_reverse_fun(*begin);
	printf("\nSTART TO REPRINT\n");
	ft_print_list(*begin);

	return (0);
}
