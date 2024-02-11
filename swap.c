#include "push_swap.h"

void swap(s_stack *stack)
{
    // Check if there are at least two nodes in the stack
    if (stack == NULL || stack->head == NULL || stack->head->next == stack->head)
    {
        printf("Nothing to swap\n");
        return;
    }

    // Get the first and second nodes
    s_node *first = stack->head;
    s_node *second = stack->head->next;

    // Swap their data
    long temp = first->data;
    first->data = second->data;
    second->data = temp;

    printf("sa\n");
}