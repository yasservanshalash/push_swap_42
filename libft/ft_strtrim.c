/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:43 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/29 18:02:06 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	exists_in_string(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		i;
	int		end;
	char	*trimmed;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	len = 0;
	while (s1[start] != '\0' && exists_in_string(s1[start], set))
		start++;
	while (end > start && exists_in_string(s1[end], set))
		end--;
	len = end - start + 1;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	while (i < len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}

// int	main(void)
// {
// 	char	s1[] = "   Hello, World!   ";
// 	char	set[] = " ";
// 	char	*trimmed;

// 	trimmed = ft_strtrim(s1, set);
// 	printf("%s\n", trimmed);	
// 	return (0);
// }

/*

static int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// Function to check if a character exists in a string
static int	exists_in_string(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1); // Character exists in the set
		j++;
	}
	return (0); // Character not found in the set
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	len;
	int	i;

	i = 0;
	start = 0;
	int end = ft_strlen(s1) - 1; // Initialize end to the last character index
	len = 0;
	// Find the number of leading characters to remove
	while (s1[start] != '\0' && exists_in_string(s1[start], set))
		start++;
	// Find the number of trailing characters to remove
	while (end > start && exists_in_string(s1[end], set))
		end--;
	// Calculate the length of the trimmed string
	len = end - start + 1; // Add 1 for the null terminator
	// Allocate memory for the trimmed string
	char *trimmed = (char *)malloc(len + 1); // +1 for the null terminator
	if (trimmed == NULL)
		return (NULL); // Memory allocation failed
	// Copy the trimmed characters to the new string
	while (i < len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	// Add the null terminator at the end
	trimmed[len] = '\0';
	return (trimmed);
}


*/
