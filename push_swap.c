#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	char	**numbers_as_strings;
	int		numbers[argc - 1];
	int		i;
	int		j;
	// stack	a;
	// stack	b; ./a.out 

	i = 1;
	j = 0;
	// take care of input arguments
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		numbers_as_strings = ft_split(argv[i], ' ');
		while (numbers_as_strings[j] != NULL)
			j++;
		i++;
		numbers_as_strings[j] = NULL;
	}
	else
	{
		while (j < argc - 1)
		{
			numbers_as_strings[j] = *ft_split(argv[i], ' ');
			j++;
			i++;
		}
		numbers_as_strings[j] = NULL;
	}
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
	free(numbers_as_strings);
	return (0);
}
