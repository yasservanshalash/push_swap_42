/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:33:29 by yshalash      #+#    #+#                 */
/*   Updated: 2024/02/05 16:55:58 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	logic(const char *str, int i, int sign, int number)
{
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] != '-' && str[i] != '+' && is_num(str[i]) == 0)
		return (-2147483648);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!is_num(str[i]))
		return (0);
	while (is_num(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (sign % 2 == 0)
		return (number);
	else
		return (number * -1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 0;
	number = 0;
	return (logic(nptr, i, sign, number));
}
