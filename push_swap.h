#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_atoi(const char *nptr);
char	**ft_split(const char *s, char delimiter);
long	*return_numbers(int argc, char **argv, int *size);
int duplicate_numbers(long *numbers, int size);

#endif
