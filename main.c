#include "push_swap.h"
#include <stdio.h>


int lstsize(s_stack *lst) {
    int i = 0;
    s_node *current = lst->head; // Start from the head of the stack

    while (current) {
        i++;
        current = current->next;
    }
    return i;
}


int main(int argc, char **argv) {
    long *numbers_array;
    int size;
    s_stack *a;
    s_stack *b;

    numbers_array = return_numbers(argc, argv, &size);
    a = array_to_stack(numbers_array, size);
    b = (s_stack *)malloc(sizeof(s_stack));
	int i = 0;

	s_node *current;
	current = a->head;
	while (i < ft_lstsize(a))
	{
		printf("%ld", current->data);
		current = current->next;
		i++;
	}
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
    return 0;
}
