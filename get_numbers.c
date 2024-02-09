#include "push_swap.h"
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
int count_strings(char *array_of_strings)
{
    int count = 0;
    while (array_of_strings != NULL)
    {
        count++;
        array_of_strings = strtok(NULL, " ");
    }
    return count;
}

void no_args(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

void one_arg(char **argv, char ***numbers_as_strings, int *j, long **numbers)
{
    *numbers_as_strings = (char **)malloc(sizeof(char *));
    if (*numbers_as_strings == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    (*numbers_as_strings)[0] = ft_strdup(argv[1]);
    *j = count_strings((*numbers_as_strings)[0]);
    *numbers = (long *)malloc(*j * sizeof(long));
    if (*numbers == NULL)
    {
        write(1, "Error\n", 6);
        exit(1);
    }
}

void more_args(char **argv, char ***numbers_as_strings, int *j, long **numbers)
{
    int number_of_numbers = 0;
    int k = 0;

    while (argv[number_of_numbers])
    {
        char *current_token = strtok(argv[number_of_numbers], " ");
        number_of_numbers += count_strings(current_token);
    }

    *numbers_as_strings = (char **)malloc((number_of_numbers + 1) * sizeof(char *));
    if (*numbers_as_strings == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    number_of_numbers = 1;
    while (argv[number_of_numbers])
    {
        char *split_result = strtok(argv[number_of_numbers], " ");
        int split_count = count_strings(split_result);
        k = 0;
        while (k < split_count)
        {
            (*numbers_as_strings)[(*j)] = ft_strdup(&split_result[k]);
            (*j)++;
            k++;
        }
        number_of_numbers++;
    }
    (*numbers_as_strings)[*j] = NULL;

    *numbers = (long *)malloc((*j) * sizeof(long));
    if (*numbers == NULL)
    {
        printf("Error\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    char **numbers_as_strings;
    long *numbers;
    int j = 0;

    if (argc < 2)
        no_args();
    else if (argc == 2)
        one_arg(argv, &numbers_as_strings, &j, &numbers);
    else
        more_args(argv, &numbers_as_strings, &j, &numbers);

    int i = 0;
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
    free(numbers);
    return (0);
}