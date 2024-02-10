#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	free_stack(s_stack *stack)
{
	s_node	*current;
	s_node	*temp;

	if (stack == NULL || stack->head == NULL)
		return ;
	current = stack->head;
	while (current->next != stack->head)
	{
		temp = current;
		current = current->next;
		free(temp); // Free the current node
	}
	free(current); // Free the last node
	stack->head = NULL;
	// Set the head pointer to NULL to indicate an empty list
	free(stack);
}

// Function to create a new Node
s_node	*create_node(long data)
{
	s_node	*node;

	node = (s_node *)malloc(sizeof(s_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// Function to push a new node onto the stack
void	push(s_stack *stack, long data)
{
	s_node	*new_node;

	new_node = create_node(data);
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
	}
	else
	{
		new_node->next = stack->head;
		new_node->prev = stack->head->prev;
		stack->head->prev->next = new_node;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
}

// Function to display the elements of the stack
void	display(s_stack *stack)
{
	s_node	*current;

	if (stack == NULL || stack->head == NULL)
	{
		printf("Stack is empty.\n");
		return ;
	}
	printf("Stack: ");
	current = stack->head;
	while (1)
	{
		printf("%ld -> ", current->data);
		current = current->next;
		if (current == stack->head)
		{
			break ;
		}
	}
	printf("NULL\n");
}

// Function to loop over an array of numbers
// and put each number in a node of a linked list called Stack
s_stack	*array_to_stack(long arr[], int size)
{
	s_stack	*stack;
	int		i;

	stack = (s_stack *)malloc(sizeof(s_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	i = 0;
	while (i < size)
	{
		push(stack, arr[i]);
		i++;
	}
	return (stack);
}
