#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	long	*numbers_array;
	int		size;

	numbers_array = return_numbers(argc, argv, &size);
	free(numbers_array);
	return (0);
}
