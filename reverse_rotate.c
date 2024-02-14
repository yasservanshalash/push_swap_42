#include "push_swap.h"
#include <stdio.h>

void	reverse_rotate(s_stack *stack)
{
	long	last_data;
	s_node	*current;

	// Check if stack a is empty or has only one element
	if (stack == NULL || stack->head == NULL
		|| stack->head->next == stack->head)
	{
		printf("No reverse rotation needed for stack a.\n");
		return ;
	}
	// Store the data of the last element
	last_data = stack->head->prev->data;
	// Traverse the stack to shift elements down by one position
	current = stack->head->prev;
	while (current != stack->head)
	{
		current->data = current->prev->data;
		current = current->prev;
	}
	// Set the stored last element as the new first element of stack a
	stack->head->data = last_data;
	printf("rra\n"); // Print confirmation
}
