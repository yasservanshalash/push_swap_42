/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:50:46 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/03 17:42:21 by yshalash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*unsigned_s;

	i = 0;
	unsigned_s = (const unsigned char *)s;
	while (i < n)
	{
		if (unsigned_s[i] == (unsigned char)c)
		{
			return ((void *)(unsigned_s + i));
		}
		i++;
	}
	return (NULL);
}
