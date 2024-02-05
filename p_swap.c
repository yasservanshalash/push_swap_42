#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char **numbers_as_strings = NULL;
    int numbers[argc - 1];
    int i;
    int j;

    i = 1;
    j = 0;
    if (argc < 2) {
        write(1, "Error\n", 6);
        return (1);
    }
    else if(argc == 2)
    {
        numbers_as_strings = ft_split(argv[1], ' ');
    }
    else
    {
        numbers_as_strings = (char **)malloc((argc - 1) * sizeof(char *));
        while (argv[i])
        {
            numbers_as_strings[j] = malloc(strlen(argv[i]) + 1);
            numbers_as_strings[j++] = ft_strdup(argv[i++]);
        }
    }
    i = 0;
    while (i < j)
    {
        numbers[i] = ft_atoi(numbers_as_strings[i]);
        i++;
    }
    i = 0;

    // print numbers
    while (i < j)
    {
        printf("%d\n", numbers[i]);
        i++;
    }
    while (i < j)
        free(numbers_as_strings[i++]);
    free(numbers_as_strings);

    return (0);
}