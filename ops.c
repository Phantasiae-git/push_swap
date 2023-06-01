/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:34:36 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/01 16:35:50 by phantasiae       ###   ########.fr       */
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

void	push(int **a, int **b, int *membersa, int membersb)
{
	int	*a2;
	int	*b2;
	int	i;

	//pushes from b to a
	if (membersb == 0)
		return ;
	a2 = malloc(sizeof(int) * (*membersa + 1));
	if (membersb > 1)
		b2 = malloc(sizeof(int) * (membersb - 1));
	i = -1;
	while (++i < (*membersa))
		a2[i + 1] = (*a)[i];
	a2[0] = (*b)[0];
	i = -1;
	while (++i < (membersb - 1))
		b2[i] = (*b)[i + 1];
	(*membersa)++;
	membersb--;
	/*ft_printf("destination array:");
	printoutput(a2, *membersa);
	ft_printf("source array:");
	printoutput(b2, *membersb);*/
	*a = a2;
	*b = b2;
}

/*void	push(int **a, int **b, int *membersa, int *membersb)
{
	int	*a2;
	int	*b2;
	int	i;

	//pushes from b to a
	if (*membersb == 0)
		return ;
	a2 = malloc(sizeof(int) * (*membersa + 1));
	if (*membersb > 1)
		b2 = malloc(sizeof(int) * (*membersb - 1));
	i = -1;
	while (++i < (*membersa))
		a2[i + 1] = (*a)[i];
	a2[0] = (*b)[0];
	i = -1;
	while (++i < (*membersb - 1))
		b2[i] = (*b)[i + 1];
	(*membersa)++;
	(*membersb)--;
	ft_printf("destination array:");
	printoutput(a2, *membersa);
	ft_printf("source array:");
	printoutput(b2, *membersb);
	*a = a2;
	*b = b2;
}*/

void	rotate(int *a, int members)
{
	int	i;
	int	temp;
	int	temp1;

	if (members < 2)
		return ;
	if (members == 2)
	{
		swap(a, members);
		return ;
	}
	i = 0;
	temp1 = a[0];
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
	int	temp1;

	if (members < 2)
		return ;
	if (members == 2)
		swap(a, members);
	i = members - 1;
	temp1 = a[members - 1];
	while (i > 0)
	{
		temp = a[i - 1];
		a[i] = temp;
		i--;
	}
	a[0] = temp1;
}
