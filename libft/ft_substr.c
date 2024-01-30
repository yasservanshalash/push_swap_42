/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:06:28 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/29 17:56:42 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int	f_strlen(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	i = start;
	j = 0;
	if ((f_strlen(s) + start) < len)
		len = f_strlen(s) + start;
	if (len > f_strlen(s) - start)
	{
		len = f_strlen(s) - start;
	}
	if (start > f_strlen(s))
		return (ft_strdup(""));
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == NULL || !s)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		substring[j] = s[i];
		i++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}
