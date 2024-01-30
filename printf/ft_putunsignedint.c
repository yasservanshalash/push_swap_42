/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:06:04 by yasser        #+#    #+#                 */
/*   Updated: 2023/11/15 15:04:06 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	digit_count(unsigned int n)
{
	unsigned int	number;
	int				count;

	number = n;
	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	ft_putusignedint(unsigned int num)
{
	char			*str;
	unsigned int	number;
	unsigned int	i;
	unsigned int	j;

	if (num == 0)
		return (write(1, "0", 1));
	if (num == 4294967295)
		return (write(1, "4294967295", 10));
	str = (char *)malloc(digit_count(num) * sizeof(char));
	if (str == NULL)
		return (-1);
	number = num;
	i = 0;
	while (number != 0)
	{
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	j = i;
	while (i-- > 0)
		write(1, &str[i], 1);
	free(str);
	return (j);
}
// int main()
// {
// 	ft_putusignedint(-10);
// }
