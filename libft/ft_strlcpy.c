/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:25:47 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/03 17:51:16 by yshalash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (size > 0)
	{
		while (i < size - 1 && source[i] != '\0')
		{
			destination[i] = source[i];
			i++;
		}
		destination[i] = '\0';
	}
	while (source[len] != '\0')
		len++;
	return (len);
}
