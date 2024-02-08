#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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
	write(1, "No arguments provided.\n", 23);
	exit(1);
}

void	one_arg(char **argv, char ***numbers_as_strings, int *count)
{
	*numbers_as_strings = (char **)malloc(sizeof(char *));
	if (!*numbers_as_strings)
	{
		write(1, "Memory allocation failed\n", 25);
		exit(EXIT_FAILURE);
	}
	(*numbers_as_strings)[0] = ft_strdup(argv[1]);
	*count = 1;
}

void	more_args(char **argv, char ***numbers_as_strings, int argc, int *count)
{
	int	i;

	*numbers_as_strings = (char **)malloc(sizeof(char *) * (argc - 1));
	if (!*numbers_as_strings)
	{
		write(1, "Memory allocation failed\n", 25);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		(*numbers_as_strings)[i - 1] = ft_strdup(argv[i]);
		(*count)++;
		i++;
	}
}

void	free_numbers_as_strings(char ***numbers_as_strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free((*numbers_as_strings)[i]);
		i++;
	}
	free(*numbers_as_strings);
}

int	main(int argc, char **argv)
{
	char	**numbers_as_strings;
	int		count;
	int		i;

	count = 0;
	if (argc < 2)
		no_args();
	else if (argc == 2)
		one_arg(argv, &numbers_as_strings, &count);
	else
		more_args(argv, &numbers_as_strings, argc, &count);
	// Print numbers
	i = 0;
	while (i < count)
	{
		printf("%s\n", numbers_as_strings[i]);
		i++;
	}
	// Free allocated memory for numbers_as_strings
	free_numbers_as_strings(&numbers_as_strings, count);
	return (0);
}
