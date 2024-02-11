#include "push_swap.h"
#include <stdio.h>


int lstsize(s_stack *lst) {
    if (lst == NULL || lst->head == NULL) {
        return 0; // Handle empty list case
    }

    int count = 0;
    s_node *current = lst->head;
    s_node *start = lst->head; // Store the starting node

    // Traverse the circular linked list
    while (1) {
        count++;
        current = current->next;
        if (current == start) {
            break; // Break the loop when we reach the starting node again
        }
    }

    return count;
}

int main(int argc, char **argv) {
    long *numbers_array;
    int size;
    s_stack *a;
    s_stack *b;

    numbers_array = return_numbers(argc, argv, &size);
    a = array_to_stack(numbers_array, size);
    b = (s_stack *)malloc(sizeof(s_stack));

	free(numbers_array);
	// display(a);
	// display(b);
	// while (isSortedDesc(a) != 1) 
	// {
    //     // Push top two elements from stack 'a' to stack 'b'
    //     push_to(b, a);
    //     push_to(b, a);
    //     // Rotate stack 'b'
    //     swap(b);
	// 	rotate(a);
	// 	rotate(a);
    //     // Push top two elements from stack 'b' back to stack 'a'
    //     push_to(a, b);
    //     push_to(a, b);
	// 	rotate(a);
    //     // Display the current state of stack 'a'
    //     display(a);
	// 	display(b);
	// }

    // printf("\nSORTED");
	free(numbers_array);
	free_stack(a);
	free_stack(b);
    return 0;
}
