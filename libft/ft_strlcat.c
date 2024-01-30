/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:56:13 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/29 17:51:29 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size == 0 || dst_len >= size)
		return (src_len + size);
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// alijn
// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
//     size_t dst_len = strlen(dst);
//     size_t src_len = strlen(src);
//     int i = 0;

//     while(src[i] != '\0' && dst_len + i + 1 < size)
//     {
//         dst[dst_len + i] = src[i];
//         i++;
//      }
//      dst[dst_len + i] = '\0';
//      if (size > dst_len)
//         return (dst_len + src_len);
//      return (size + src_len);
// }

// chatgpt

// size_t ft_strlcat(char *dst, const char *src, size_t size)
// {
//     size_t dst_len = 0;
//     size_t src_len = 0;
//     size_t total_len;

//     // Calculate the length of the destination string
//     while (dst_len < size && dst[dst_len] != '\0')
//         dst_len++;

//     // Calculate the length of the source string
//     while (src[src_len] != '\0')
//         src_len++;

//     // Calculate the total length if there was enough space
//     total_len = dst_len + src_len;

//     // Handle the case where there's not enough space
//     if (size <= dst_len)
//         return (size + src_len);

//     // Copy characters from src to dst (up to size - dst_len - 1 characters)
//     size_t i = 0;
//     while (dst_len + i < size - 1 && src[i] != '\0')
//     {
//         dst[dst_len + i] = src[i];
//         i++;
//     }

//     // Null-terminate the concatenated string
//     dst[dst_len + i] = '\0';

//     return (total_len);
// }

// also chatgpt

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	dst_len;
// 	size_t	src_len;
// 	size_t	i;

// 	dst_len = 0;
// 	src_len = 0;
// 	i = 0;
// 	// Calculate the length of the destination string
// 	while (dst[dst_len] && dst_len < size)
// 		dst_len++;
// 	// Calculate the length of the source string
// 	while (src[src_len])
// 		src_len++;
// 	// If size is 0 or dst is longer than size, return src_len + size
// 	if (size == 0 || dst_len >= size)
// 		return (src_len + size);
// 	// Copy src to dst, ensuring there's room for the null-terminator
// 	while (src[i] && dst_len + i < size - 1)
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	// Null-terminate the destination string
// 	dst[dst_len + i] = '\0';
// 	// Return the total length of the concatenated strings
// 	return (dst_len + src_len);
// }
