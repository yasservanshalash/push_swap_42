/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 09:17:11 by yshalash      #+#    #+#                 */
/*   Updated: 2024/02/05 15:42:58 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_words_in_string(const char *str, char delimiter)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str != delimiter && !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if (*str == delimiter)
		{
			in_word = 0;
		}
		str++;
	}
	return (word_count);
}

static char	*duplicate_word(const char *str, int start, int end)
{
	char	*word;
	int		word_length;
	int		i;

	word_length = end - start;
	i = 0;
	word = malloc((word_length + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

static void	free_word(char **result, size_t *j)
{
	while (*j > 0)
		free(result[--(*j)]);
	free(result);
}

static int	logic(const char *s, char delimiter, char **result, size_t *j)
{
	size_t	i;
	int		start_index;
	char	*word;

	start_index = -1;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != delimiter && start_index < 0)
			start_index = i;
		else if ((s[i] == delimiter || i == ft_strlen(s)) && start_index >= 0)
		{
			word = duplicate_word(s, start_index, i);
			if (word == NULL)
			{
				free_word(result, &*j);
				return (0);
			}
			result[(*j)++] = word;
			start_index = -1;
		}
		(i)++;
	}
	return (1);
}

char	**ft_split(const char *s, char delimiter)
{
	char	**result;
	size_t	j;

	if (!s)
		return (NULL);
	result = malloc((count_words_in_string(s, delimiter) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	j = 0;
	if (!logic(s, delimiter, result, &j))
	{
		return (NULL);
	}
	result[j] = NULL;
	return (result);
}

// static size_t	ft_strlen(const char *str)
// {
// 	size_t	length;

// 	length = 0;
// 	while (str[length] != '\0')
// 		length++;
// 	return (length);
// }

// static int	count_words_in_string(const char *str, char delimiter)
// {
// 	int	word_count;
// 	int	in_word;

// 	word_count = 0;
// 	in_word = 0;
// 	while (*str != '\0')
// 	{
// 		if (*str != delimiter && !in_word)
// 		{
// 			in_word = 1;
// 			word_count++;
// 		}
// 		else if (*str == delimiter)
// 		{
// 			in_word = 0;
// 		}
// 		str++;
// 	}
// 	return (word_count);
// }

// static char	*duplicate_word(const char *str, int start, int end)
// {
// 	char	*word;
// 	int		word_length;
// 	int		i;

// 	word_length = end - start;
// 	i = 0;
// 	word = (char *)malloc((word_length + 1) * sizeof(char));
// 	while (start < end)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(const char *s, char delimiter)
// {
// 	size_t	str_length;
// 	size_t	word_count;
// 	char	**result;
// 	size_t	i;
// 	size_t	j;
// 	int		start_index;

// 	str_length = ft_strlen(s);
// 	word_count = count_words_in_string(s, delimiter);
// 	result = (char **)malloc((word_count + 1) * sizeof(char *));
// 	if (!s || result == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	start_index = -1;
// 	while (i <= str_length)
// 	{
// 		if (s[i] != delimiter && start_index < 0)
// 			start_index = i;
// 		else if ((s[i] == delimiter || i == str_length) && start_index >= 0)
// 		{
// 			result[j++] = duplicate_word(s, start_index, i);
// 			start_index = -1;
// 		}
// 		i++;
// 	}
// 	result[j] = NULL;
// 	return (result);
// }

// int main(void)
// {
//     char    **result;
//     int     num_strings;
//     int     i;

//     result = ft_split("Monday,Tuesday,Wednesday", ',');
//     if (result == NULL)
//     {
//         printf("Memory allocation error.\n");
//         return (1);
//     }

//     // Calculate the number of strings in the array.
//     num_strings = 0;
//     while (result[num_strings] != NULL)
//     {
//         num_strings++;
//     }

//     i = 0;
//     while (i < num_strings)
//     {
//         printf("%s\n", result[i]); // Print each string in the array
//         i++;
//     }

//     // Free the memory allocated for the result array.
//     i = 0;
//     while (i < num_strings)
//     {
//         free(result[i]);
//         i++;
//     }
//     free(result);
//     return (0);
// }

// static int	word_counter(char const *s, char delimiter)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != delimiter)
// 		{
// 			count++;
// 			while (s[i] != '\0' && s[i] != delimiter)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		words;
// 	char	**result;
// 	int		k;

// 	i = 0;
// 	words = word_counter(s, c);
// 	result = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < words)
// 	{
// 		while (*s == c)
// 			s++;
// 		j = 0;
// 		while (s[j] != c && s[j] != '\0')
// 			j++;
// 		result[i] = (char *)malloc((j + 1) * sizeof(char));
// 		if (result[i] == NULL)
// 		{
// 			k = 0;
// 			while (k < i)
// 			{
// 				free(result[k]);
// 				k++;
// 			}
// 			free(result);
// 			return (NULL);
// 		}
// 		strncpy(result[i], s, j);
// 		result[i][j] = '\0';
// 		s += j;
// 		i++;
// 	}
// 	result[i] = NULL;
// 	return (result);
// }

// int	main(void)
// {
// 	char	**result;
// 	int		numStrings;
// 	int		i;

// 	result = ft_split("Monday,Tuesday,Wednesday", ',');
// 	if (result == NULL)
// 	{
// 		printf("Memory allocation error.\n");
// 		return (1);
// 	}
// 	// Calculate the number of strings in the array.
// 	numStrings = 0;
// 	while (result[numStrings] != NULL)
// 	{
// 		numStrings++;
// 	}
// 	i = 0;
// 	while (i < numStrings)
// 	{
// 		printf("%s\n", result[i]); // Print each string in the array
// 		i++;
// 	}
// 	// Free the memory allocated for the result array.
// 	i = 0;
// 	while (i < numStrings)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
