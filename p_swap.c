#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long has_string(long numbers[], int size)
{
    int i;
    int invalid;

    invalid = 0;
    for (i = 0; i < size; i++)
    {
        if (numbers[i] < -2147483648 || numbers[i] > 2147483647)
        {
            invalid = 1;
            break;
        }
    }
    return invalid;
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

int hasDuplicates(char* strings[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (ft_strncmp(strings[i], strings[j], length) == 0) {
                // Found a duplicate
                return 1;
            }
        }
    }
    // No duplicates found
    return 0;
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
		if (hasDuplicates(numbers_as_strings, j) == 1)
		{
			printf("DUPLICATES FOUND \n");
			exit (1);

		}
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
	if (has_string(numbers, j) == 1)
	{
		write(1, "Error: Invalid input\n", 21);
		exit(1);
	}
	if (has_duplicates(numbers, j) == 1)
	{
		write(1, "Error: Duplicate numbers found\n", 31);
		exit(1);
	}
	// print numbers	
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
