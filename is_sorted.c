#include "push_swap.h"

int	is_sorted(s_stack *stack)
{
	s_node	*current;
	s_node	*start;

	current = stack->head;
	// If the stack is empty or contains only one element, it is considered sorted
	if (current == NULL || current->next == current)
		return (1);
	// Keep track of the starting node
	start = current;
	// Traverse the circular stack and check if each element is less than or equal to the next one
	while (1)
	{
		if (current->data > current->next->data)
			return (0); // Stack is not sorted
		current = current->next;
		if (current == start)
			break ; // Stop the loop when we reach the starting node again
	}
	// Stack is sorted
	return (1);
}

int	isSortedDesc(s_stack *stack)
{
	s_node	*current;

	// Check if the stack is empty
	if (stack->head == NULL)
		return (1); // Consider an empty stack sorted
	// Traverse the stack till the last node
	current = stack->head;
	while (current->next != stack->head)
	{
		// If a node is greater than or equal to its next, return false
		if (current->data < current->next->data)
			return (0);
		current = current->next;
	}
	// If loop completes without returning false, return true
	return (1);
}
