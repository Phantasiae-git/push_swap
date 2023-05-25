/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:02:01 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/24 21:12:34 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer(unsigned long int n, int flag, int flag2)
{
	int	a;
	int	count;

	count = 0;
	if (!flag && n == 0)
		return (write(1, "(nil)", 5));
	if (!flag2)
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (n >= 16)
		count += putpointer(n / 16, flag, 1);
	if (flag)
		a = UP[n % 16];
	else
		a = LOW[n % 16];
	write(1, &a, 1);
	count++;
	return (count);
}

int	puthexa(unsigned int n, int flag)
{
	int	a;
	int	count;

	count = 0;
	if (n >= 16)
		count += puthexa(n / 16, flag);
	if (flag)
		a = UP[n % 16];
	else
		a = LOW[n % 16];
	write(1, &a, 1);
	count++;
	return (count);
}
