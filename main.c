#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	long			*numbers_array;
	int				size;
	struct s_stack	*a;

	numbers_array = return_numbers(argc, argv, &size);
	a = array_to_stack(numbers_array, size);
	display(a);
	free(numbers_array);
	free(a);
	return (0);
}
