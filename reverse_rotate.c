#include "push_swap.h"
#include <stdio.h>

void reverse_rotate(s_stack *stack)
{
    // Check if stack a is empty or has only one element
    if (stack == NULL || stack->head == NULL || stack->head->next == stack->head)
    {
        printf("No reverse rotation needed for stack a.\n");
        return;
    }

    // Store the data of the last element
    long last_data = stack->head->prev->data;

    // Traverse the stack to shift elements down by one position
    s_node *current = stack->head->prev;
    do
    {
        current->data = current->prev->data;
        current = current->prev;
    } while (current != stack->head->prev);

    // Set the stored last element as the new first element of stack a
    stack->head->data = last_data;

    printf("rra\n"); // Print confirmation
}
