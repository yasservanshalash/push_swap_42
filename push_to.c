#include "push_swap.h"
#include <stdio.h>

void	push_to(s_stack *stack_to, s_stack *stack_from)
{
	long	data;
	s_node	*temp;

	// Check if stack b is empty
	if (stack_from == NULL || stack_from->head == NULL)
	{
		printf("Stack b is empty. Cannot push.\n");
		return ;
	}
	// Pop the top element from stack b
	data = stack_from->head->data;
	temp = stack_from->head;
	// Adjust the head of stack b
	if (stack_from->head->next == stack_from->head)
		stack_from->head = NULL;
	else
	{
		stack_from->head->next->prev = stack_from->head->prev;
		stack_from->head->prev->next = stack_from->head->next;
		stack_from->head = stack_from->head->next;
	}
	// Push the popped element onto the top of stack a
	push(stack_to, data);
	free(temp); // Free the memory of the popped node
}
