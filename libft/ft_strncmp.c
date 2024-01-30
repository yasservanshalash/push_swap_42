/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 11:42:17 by yshalash      #+#    #+#                 */
/*   Updated: 2023/11/06 16:57:11 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*string1;
	const unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if ((string1 && n == 0) || (string2 && n == 0))
		return (0);
	if (string1[i] == '\0')
		return (0 - string2[i]);
	if (s2[i] == '\0')
		return (string1[i] - 0);
	while (i < n && string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (string1[i] - string2[i]);
}
