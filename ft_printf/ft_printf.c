/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:11:54 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/25 02:12:43 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	b(int c, va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	if (c == 'u')
	{
		str = ft_itoa_unsigned(va_arg(ap, unsigned int));
		count = putstr(str);
		free(str);
	}
	else if (c == 'x')
		count = puthexa(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		count = puthexa(va_arg(ap, unsigned int), 1);
	else if (c == 'p')
		count = putpointer(va_arg(ap, unsigned long int), 0, 0);
	return (count);
}

int	conversion(int c, va_list ap)
{
	int		count;
	int		a;
	char	*str;

	count = 1;
	if (c == 'c')
	{
		a = va_arg(ap, int);
		write(1, &a, 1);
	}
	else if (c == '%')
		write(1, "%%", 1);
	else if (c == 's')
		count = putstr(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
	{
		str = ft_itoa(va_arg(ap, int));
		count = putstr(str);
		free(str);
	}
	else
		count = b(c, ap);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		count1;

	i = 0;
	count = 0;
	count1 = 0;
	va_start(ap, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
			count1 += conversion(s[++i], ap);
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count1 + count);
}

// int	main(void)
// {
// 	int a;

// 	a = 1;
// 	// ft_printf("%c\n", '1');
// 	// ft_printf("%s\n", a);
// 	// ft_printf("%d\n", 234);
// 	printf("%i\n", ft_printf("%p\n", &a));
// 	// printf(" NULL %s NULL ", (char *)NULL);
// 	// printf("%i\n", ft_printf("%X\n", 29));
// 	printf("%p", &a);
// 	return (0);
// }
