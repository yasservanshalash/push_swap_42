/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:40 by yshalash          #+#    #+#             */
/*   Updated: 2023/10/29 16:14:46 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// Online C compiler to run C program online
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number == 0)
	{
		write(fd, "0", 1);
	}
	if (number > 0)
	{
		if (number > 9)
		{
			ft_putnbr_fd(number / 10, fd);
		}
		ft_putchar(((number % 10) + 48), fd);
	}
}

// static int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// static void	ft_reverse_string(char *str)
// {
// 	int		length;
// 	int		start;
// 	int		end;
// 	char	temp;

// 	length = ft_strlen(str);
// 	start = 0;
// 	end = length - 1;
// 	while (start < end)
// 	{
// 		temp = str[start];
// 		str[start] = str[end];
// 		str[end] = temp;
// 		start++;
// 		end--;
// 	}
// }

// static int	digit_count(int n)
// {
// 	int	number;
// 	int	count;

// 	number = n;
// 	count = 0;
// 	while (number != 0)
// 	{
// 		number /= 10;
// 		count++;
// 	}
// 	return (count);
// }

// static char	*ft_itoa(int n)
// {
// 	int		digit_num;
// 	int		number;
// 	char	*result;
// 	int		i;

// 	digit_num = digit_count(n);
// 	number = n;
// 	i = 0;
// 	result = (char *)malloc(sizeof(char) * (digit_num + 2));
// 	if (n < 0)
// 	{
// 		result[0] = '-';
// 		number = -number;
// 		i = 1;
// 	}
// 	while (i < digit_num + (n < 0))
// 	{
// 		result[i] = (number % 10) + '0';
// 		number /= 10;
// 		i++;
// 	}
// 	result[i] = '\0';
// 	ft_reverse_string(result + (n < 0));
// 	return (result);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	*number;

// 	number = ft_itoa(n);
// 	if (n == 0)
// 		write(fd, "0", 1);
// 	else if (n == -2147483648)
// 		write(fd, "-2147483648", 11);
// 	else
// 	{
// 		if (number == NULL)
// 		{
// 			return ;
// 		}
// 		write(fd, number, ft_strlen(number));
// 	}
// 	free(number);
// }

/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}
*/

/*
// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

static void	ft_reverse_string(char *str)
{
	int		length;
	int		start;
	int		end;
	char	temp;

	length = ft_strlen(str);
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

void	ft_putnbr_fd(int n, int fd)
{
	int	number;
	int	count;
	int	temp;

	number = n;
	count = digit_count(number);
	temp = 0;
	while(count != 0)
	{
		temp = (number % 10) + '0';
		write(fd, &temp, 1);
		number = number / 10;
		count--;
	}
}

int	main(void) {
	// Write C code here
	ft_putnbr_fd(758,1);

	return (0);
}
*/
