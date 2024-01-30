/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:03:57 by yasser        #+#    #+#                 */
/*   Updated: 2023/11/15 14:38:33 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	digit_count_hex(unsigned long long n)
{
	int	count;

	if (n == 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	pointer_number;
	char				*str;
	char				*base;
	int					i;
	int					j;

	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	pointer_number = (unsigned long long)ptr;
	str = (char *)malloc((digit_count_hex(pointer_number) + 2) * sizeof(char));
	base = "0123456789abcdef";
	i = 0;
	while (pointer_number != 0)
	{
		str[i++] = base[pointer_number % 16];
		pointer_number /= 16;
	}
	j = i;
	write(1, "0x", 2);
	while (i-- > 0)
		write(1, &str[i], 1);
	free(str);
	return (j + 2);
}

// static int	digit_count(unsigned int n)
// {
// 	int	number;
// 	int	count;

// 	number = n;
// 	count = 0;
// 	while (number != 0)
// 	{
// 		number /= 10;
// 		count++;
// 	}
// 	return (count);
// }

// int	ft_putptr(void *ptr)
// {
// 	unsigned long long	pointer_number;
// 	char				*str;
// 	char				*base;
// 	int					i;
// 	int					j;

// 	if (ptr == NULL) {
//         write(1, "(nil)", 5);
//         return (5);
//     }
// 	pointer_number = (unsigned long long)ptr;
// 	str = (char *)malloc((digit_count(pointer_number)) * sizeof(char));
// 	base = "0123456789abcdef";
// 	i = 0;
// 	while (pointer_number != 0)
// 	{
// 		str[i] = base[pointer_number % 16];
// 		pointer_number /= 16;
// 		i++;
// 	}
// 	j = i;
// 	write(1, "0x", 2);
// 	while (i > 0)
// 	{
// 		i--;
// 		write(1, &str[i], 1);
// 	}
// 	free(str);
// 	return (j + 2);
// }
// int main()
// {
// 	int i = 9;
// 	int *p = (int*)malloc(sizeof(int));
// 	printf("%d", ft_putptr(p));
// 	printf("%d", printf("\n%p", p));
// }
