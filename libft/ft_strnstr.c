/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:56:02 by yasser            #+#    #+#             */
/*   Updated: 2023/10/29 16:13:42 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j++) < len)
			{
				count++;
				if (count == (int)ft_strlen(little))
					return ((char *)&big[i]);
			}
			count = 0;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

// char	*ft_strnstr(const char *big,	const char *little, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		count;

// 	i = 0;
// 	j = 0;
// 	count = 0;
// 	if (little[0] == '\0')
// 		return ((char *)big);
// 	while(big[i] != '\0' && i < len)
// 	{
// 		if(big[i] == little[j])
// 		{
// 			while(big[i] == little[j])
// 			{
// 				// printf("%c", little[j]);
// 				count++;
// 				j++;
// 			}
// 			if(count == (int)ft_strlen(little))
// 				return ((char *)&big[i - j + 1]);
// 		}
// 					i++;
// 	}
// 	return (NULL);
// }
