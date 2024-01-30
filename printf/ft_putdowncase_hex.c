/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdowncase_hex.c                               :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:08:23 by yasser        #+#    #+#                 */
/*   Updated: 2023/11/15 15:02:47 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	digit_count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_put_downcase_hex(unsigned int num)
{
	char	*str;
	char	*base;
	int		i;
	int		j;

	if (num == 0)
		return (write(1, "0", 1));
	str = (char *)malloc((digit_count(num) + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	base = "0123456789abcdef";
	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num != 0)
	{
		str[i++] = base[num % 16];
		num /= 16;
	}
	str[i] = '\0';
	j = i;
	while (i-- > 0)
		write(1, &str[i], 1);
	free(str);
	return (j);
}
