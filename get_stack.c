#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new Node
struct s_node	*create_node(long data)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// Function to push a new node onto the stack
void	push(struct s_stack *stack, long data)
{
	struct s_node	*new_node;

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
void	display(struct s_stack *stack)
{
	struct s_node	*current;

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
struct s_stack	*array_to_stack(long arr[], int size)
{
	struct s_stack	*stack;
	int				i;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->head = NULL;
	i = 0;
	while (i < size)
	{
		push(stack, arr[i]);
		i++;
	}
	return (stack);
}
