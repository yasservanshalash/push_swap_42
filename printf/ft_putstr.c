/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:03:03 by yasser        #+#    #+#                 */
/*   Updated: 2023/11/14 15:30:48 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
