#include "push_swap.h"

int	count_strings(char **array_of_strings)
{
	int	count;

	count = 0;
	while (array_of_strings[count] != NULL)
	{
		count++;
	}
	return (count);
}

void	no_args(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	one_arg(char **argv, char ***numbers_as_strings, int *j)
{
	*numbers_as_strings = ft_split(argv[1], ' ');
	*j = count_strings(*numbers_as_strings);
}

void	more_args(char **argv, char ***numbers_as_strings, int *i, int *j, long **numbers)
{
	int		number_of_numbers;
	char	**split_result;
	int		split_count;
	int		k;

	number_of_numbers = 0;
	k = 0;
	while (argv[*i])
		number_of_numbers += count_strings(ft_split(argv[(*i)++], ' '));
	*numbers_as_strings = (char **)malloc((number_of_numbers + 1)
			* sizeof(char *));
	if (*numbers_as_strings == NULL)
	{
		printf("Error\n");
		free(*numbers_as_strings);
		exit(1);
	}
	*i = 1;
	while (argv[*i])
	{
		split_result = ft_split(argv[(*i)++], ' ');
		split_count = count_strings(split_result);
		k = 0;
		while (k < split_count)
			(*numbers_as_strings)[(*j)++] = ft_strdup(split_result[k++]);
	}
	(*numbers_as_strings)[*j] = NULL;
    *numbers = (long *)malloc(number_of_numbers * sizeof(long));
		if (*numbers == NULL)
    {
        printf("Error\n");
        exit(1);
    }
}
int	main(int argc, char **argv)
{
	char	**numbers_as_strings;
	long	*numbers;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2)
		no_args();
	else if (argc == 2)
		one_arg(argv, &numbers_as_strings, &j);
	else
        more_args(argv, &numbers_as_strings, &i, &j, &numbers);
	i = 0;
	while (i < j)
    {
        numbers[i] = ft_atoi(numbers_as_strings[i]);
        i++;
    }
	i = 0;
	while (i < j)
		printf("%ld\n", numbers[i++]);
	i = 0;
	while (i < j)
		free(numbers_as_strings[i++]);
	free(numbers_as_strings);
	return (0);
}
