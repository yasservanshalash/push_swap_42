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
int	main(int argc, char **argv)
{
	char	**numbers_as_strings;
	long	*numbers;
	int		i;
	int		j;
	int		number_of_numbers;
	char	**split_result;
	int		split_count;
	int		k;

	i = 1;
	j = 0;
	number_of_numbers = 0;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (argc == 2)
	{
		numbers_as_strings = ft_split(argv[1], ' ');
		j = count_strings(numbers_as_strings);
	}
	else
	{
		while (argv[i])
		{
			number_of_numbers += count_strings(ft_split(argv[i], ' '));
			i++;
		}
		numbers_as_strings = (char **)malloc((number_of_numbers + 1)
				* sizeof(char *));
		if (numbers_as_strings == NULL)
        {
            printf("Error\n");
            free (numbers_as_strings);
			exit(1);
        }
		i = 1;
		while (argv[i])
		{
			split_result = ft_split(argv[i], ' ');
			split_count = count_strings(split_result);
			k = 0;
			while (k < split_count)
			{
				numbers_as_strings[j] = ft_strdup(split_result[k]);
				j++;
				k++;
			}
			i++;
		}
		numbers_as_strings[j] = NULL;
	}
	i = 0;
	printf("number_of_numbers: %d\nsplit_count: %d\n j: %d", number_of_numbers, split_count, j);
	numbers = (long *)malloc(number_of_numbers * sizeof(long));
	while (i < j)
	{
		numbers[i] = ft_atoi(numbers_as_strings[i]);
		i++;
	}
	i = 0;
	while (i < j)
	{
		printf("%ld\n", numbers[i]);
		i++;
	}
	i = 0;
	while (i < j)
		free(numbers_as_strings[i++]);
	free(numbers_as_strings);
	return (0);
}
