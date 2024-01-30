/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:24 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/31 21:39:11 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Online C compiler to run C program online
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_reverse_string(char *str)
{
	int		length;
	int		start;
	int		end;
	char	temp;

	length = f_strlen(str);
	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static int	digit_count(int n)
{
	int	number;
	int	count;

	number = n;
	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*logic(int digit_num, int number, int n, char *result)
{
	int	i;

	i = 0;
	if (n >= 0)
		result = (char *)malloc(sizeof(char) * (digit_num + 1));
	if (n < 0)
		result = (char *)malloc(sizeof(char) * (digit_num + 2));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		number = -number;
		i = 1;
	}
	while (i < digit_num + (n < 0))
	{
		result[i++] = (number % 10) + '0';
		number /= 10;
	}
	result[i] = '\0';
	ft_reverse_string(result + (n < 0));
	return (result);
}

char	*ft_itoa(int n)
{
	int		digit_num;
	int		number;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = NULL;
	digit_num = digit_count(n);
	number = n;
	return (logic(digit_num, number, n, result));
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-515611));
// 	return (0);
// }
