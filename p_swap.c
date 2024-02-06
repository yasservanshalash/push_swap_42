#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	has_string(long numbers[])
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (numbers[i])
	{
		if (!(numbers[i] > -2147483648 && numbers[i] < 2147483647))
			valid = 1;
		i++;
	}
	return (valid);
}
long has_duplicates(long arr[], int size) {
    int i = 0;
    while (i < size - 1) {
        int j = i + 1;
        while (j < size) {
            if (arr[i] == arr[j]) {
                return 1; // Duplicates found
            }
            j++;
        }
        i++;
    }
    return 0; // No duplicates found
}
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
	long	numbers[argc - 1];
	int		i;
	int		j;

	numbers_as_strings = NULL;
	i = 1;
	j = 0;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	else if (argc == 2)
	{
		numbers_as_strings = ft_split(argv[1], ' ');
		j = count_strings(numbers_as_strings);
	}
	else
	{
		numbers_as_strings = (char **)malloc((argc - 1) * sizeof(char *));
		while (argv[i])
		{
			numbers_as_strings[j] = malloc(strlen(argv[i]) + 1);
			numbers_as_strings[j] = ft_strdup(argv[i]);
			i++;
			j++;
		}
	}
	i = 0;
	while (i < j)
	{
		numbers[i] = ft_atoi(numbers_as_strings[i]);
		i++;
	}
	// print numbers
	i = 0;
	while (i < j)
	{
		if (has_string(numbers) != 0 || has_duplicates(numbers, j) != 0)
		{
			printf("Error parsing numbers");
			exit (1);
		}
		else
			printf("%ld\n", numbers[i]);
		i++;
	}
	i = 0;
	while (i < j)
		free(numbers_as_strings[i++]);
	free(numbers_as_strings);
	return (0);
}
