/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:11 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/03 17:49:01 by yshalash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
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

// int main()
// {
// 	char str[] = "Hello";
// 	char str2[] = "Hello";
// 	ft_memset(str, '&', 3);
//     memset(str2, '&', 3);
//     printf("%s\n", str);
//     printf("%s", str2);
// 	return 0;
// }
