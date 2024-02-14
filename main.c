#include "push_swap.h"
#include <stdio.h>

int	lstsize(s_stack *lst)
{
	int		count;
	s_node	*current;

	if (lst == NULL || lst->head == NULL)
	{
		return (0); // Handle empty list case
	}
	count = 0;
	current = lst->head;
	s_node *start = lst->head; // Store the starting node
	// Traverse the circular linked list
	while (1)
	{
		count++;
		current = current->next;
		if (current == start)
		{
			break ; // Break the loop when we reach the starting node again
		}
	}
	return (count);
}

int	main(int argc, char **argv)
{
	long	*numbers_array;
	int		size;
	s_stack	*a;
	s_stack	*b;

	numbers_array = return_numbers(argc, argv, &size);
	a = array_to_stack(numbers_array, size);
	b = (s_stack *)malloc(sizeof(s_stack));
	while (!isSortedDesc(a))
	{
		while (lstsize(a) > 0)
		{
			push_to(b, a);
			if (b->head->data > b->head->next->data)
				swap(b);
		}
		while (lstsize(b) > 0)
			push_to(a, b);
		display(a);
	}
	free(numbers_array);
	free_stack(a);
	free(b);
	return (0);
}
