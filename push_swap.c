#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

int main(int argc, char **argv)
{
    char **numbers_as_strings = NULL;
    int *numbers;
    int i, j;

    // take care of input arguments
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    
    numbers_as_strings = ft_split(argv[1], ' ');
    j = 0;

    // count the number of elements in the split array
    while (numbers_as_strings[j])
        j++;

    numbers = (int *)malloc(j * sizeof(int));

    // turn strings into numbers
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

    for (i = 0; i < j; i++)
    {
        free(numbers_as_strings[i]);
    }
    free(numbers_as_strings);

    // Free the dynamically allocated numbers array
    free(numbers);

    return (0);
}


// struct stackNode {
//     int data;
//     struct stackNode* next;
// };
// typedef struct stackNode stack;

// stack	*ft_lstnew(void *content)
// {
// 	stack	*list;

// 	list = (stack *)malloc(sizeof(stack));
// 	if (!list)
// 		return (NULL);
// 	list->data = content;
// 	list->next = NULL;
// 	return (list);
// }

// void	ft_lstadd_back(stack **lst, stack *new)
// {
// 	stack	*current;

// 	current = *lst;
// 	if (!new || !lst)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = new;
// }
