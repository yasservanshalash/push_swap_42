/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:23:33 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/16 14:23:34 by yshalash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	if (s == NULL)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	to_upper(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	printf("%d", index);
// 	return (c);
// }
// int	main(void)
// {
// 	// Write C code here
// 	printf("%s", ft_strmapi("hello", toUpper));
// 	return (0);
// }
