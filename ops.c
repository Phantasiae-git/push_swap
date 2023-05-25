/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:34:36 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/25 14:52:37 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int members)
{
	int	temp;

	if (members < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	push(int *a, int *b, int membersa, int membersb)
{
	int	*a2;
	int	*b2;
	int	i;
//pushes from B to A
	if (membersb == 0)
		return ;
	a2 = (int *)malloc(membersa + 1);
	b2 = (int *)malloc(membersb - 1);
	i = -1;
	while (++i < (membersa - 1))
		a2[i + 1] = a[i];
	a2[0] = b[0];
	i = -1;
	while (++i < (membersb - 1))
		b2[i] = b[i + 1];
	free(a);
	free(b);
}

void	rotate(int *a, int members)
{
	int	i;
	int	temp;
	int temp1;

	if (members < 2)
		return ;
	if (members == 2)
		swap(a, members);
	i = 0;
	temp1=a[0];
	while (i < (members - 1))
	{
		temp = a[i + 1];
		a[i] = temp;
		i++;
	}
	a[members - 1] = temp1;
}

void	revrotate(int *a, int members)
{
	int	i;
	int	temp;
	int temp1;

	if (members < 2)
		return ;
	if (members == 2)
		swap(a, members);
	i = members-1;
	temp1=a[members-1];
	while (i > 0)
	{
		temp = a[i-1];
		a[i] = temp;
		i--;
	}
	a[0] = temp1;
}
