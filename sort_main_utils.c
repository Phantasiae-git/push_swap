/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:26:51 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/02 18:33:36 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *members(){
	static int membersa;

	return &membersa;
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	average(int *stack, int members)
{
	int i;
	int total;
	int avg;
	int diff;

	i = -1;
	total = 0;
	while (++i < members)
		total += stack[i];
	avg = total / members;
	i = 0;
	diff = abs(stack[i] - avg);
	total = diff;
	while (++i < members)
	{
		if (abs(stack[i] - avg) < diff)
		{
			diff = stack[i] - avg;
			total = i;
		}
	}
	return (total);
}