/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 09:54:01 by yshalash      #+#    #+#                 */
/*   Updated: 2023/11/06 17:57:35 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && (count * size) / size != count)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	else
		ft_memset(p, 0, count * size);
	return (p);
}

// int main()
// {
//     printf("My func: %s\n", (char *)ft_calloc(SIZE_MAX,5));
//     printf("My func: %s\n", (char *)calloc(SIZE_MAX,5));
//     return 0;
// }