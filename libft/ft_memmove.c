/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:11:12 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/28 13:54:38 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;
	size_t	i;

	source = (char *)src;
	destination = (char *)dst;
	i = 0;
	if (!(source || destination) || len == 0)
		return (destination);
	if (source < destination)
	{
		while (len-- > 0)
			destination[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
