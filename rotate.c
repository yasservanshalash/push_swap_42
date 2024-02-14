#include "push_swap.h"
#include <stdio.h>

void	rotate(s_stack *stack)
{
	long	first_data;
	s_node	*current;

	// Check if stack b is empty or has only one element
	if (stack == NULL || stack->head == NULL
		|| stack->head->next == stack->head)
	{
		printf("No rotation needed for stack b.\n");
		return ;
	}
	// Store the data of the first element
	first_data = stack->head->data;
	// Traverse the stack to shift elements up by one position
	current = stack->head;
	while (current != stack->head->prev)
	{
		current->data = current->next->data;
		current = current->next;
	}
	// Set the stored first element as the new last element of stack b
	stack->head->prev->data = first_data;
	printf("rb\n"); // Print confirmation
}
