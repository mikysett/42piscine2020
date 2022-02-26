// ex00
int		main(int argc, char **argv)
{
	char *str_cp;

	while (argc > 1)
	{
		str_cp = ft_strdup(argv[argc - 1]);
		printf("%s\n", str_cp);
		argc--;
	}
	return (0);
}

// ex01
int	main(void)
{
	int *res;
	int i;

	res = ft_range(0, 10);
	for (i = 0 ; i < 10 ; i++)
		printf("%d . ", res[i]);
	return (0);
}

// ex02

int	main(void)
{
	int **res;
	int *inttab;
	int i;
	int test;
	int size;

	inttab = &test;
	res = &inttab;
	size = ft_ultimate_range(res, -5, 5);
	if (size == -1)
	{
		return (1);
	}
	printf("SIZE: %d\n", size);
	for (i = 0; i < size; i++)
		printf("%d ", (*res)[i]);
	printf("\n\n\n");
	return (0);
}

// ex03

int		main(int argc, char **argv)
{
	char *res;

	res = ft_strjoin(0, argv, "|");
	if(argc && res)
		printf("%s\n\n\n", res);
	return (0);
}

// ex04

int		main(int argc, char **argv)
{
	char *result;

	if (argc >= 4)
		result = ft_convert_base(argv[1], argv[2], argv[3]);
	else
		result = 0;
	printf("result:%s", result);
	return (0);
}

// ex05

int		main(int argc, char **argv)
{
	char **res;

	printf("String   : %s\n", argv[1]);
	printf("Separator: %s\n\n", argv[2]);
	res = ft_split(argv[1], argv[2]);
	while (*res && argc)
		printf("%s\n", *(res++));
	return (0);
}
