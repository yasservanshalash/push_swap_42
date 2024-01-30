/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:55:15 by yasser        #+#    #+#                 */
/*   Updated: 2023/12/21 14:34:26 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	conditions(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putusignedint(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_put_downcase_hex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_put_upcase_hex(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putpercentsign());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			counter;

	va_start(args, str);
	i = 0;
	counter = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			counter += conditions(str[i++], args);
		}
		else
		{
			ft_putchar(str[i++]);
			counter++;
		}
	}
	va_end(args);
	return (counter);
}

// int	main(void)
// {
// 	ft_printf("hello world");
// 	int	*ptr;

// 	ptr = malloc(sizeof(int));
// 	ft_printf("%d\n", ft_printf("%p\n%s\n%X\n", ptr, "hello world", 420));
// 	printf("%d\n", printf("%p\n%s\n%X\n", ptr, "hello world", 420));
// }