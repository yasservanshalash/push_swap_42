/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:43 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/28 13:55:34 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	if ((char)c < 0)
	{
		return ((char *)s);
	}
	i = 0;
	index = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			index = i;
		i++;
	}
	if (index >= 0)
		return ((char *)&s[index]);
	else if ((char)c == 0 && s[i] == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
