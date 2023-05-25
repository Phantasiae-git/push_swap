/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:05:28 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:50 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printoutput(int *stacka, int membersa)
{
	int i;
	
	i=0;
	while(i<membersa)
		ft_printf("%i ", stacka[i++]);
	ft_printf("Success!\n");
	exit(0);
}

void sort3(int *a, int membersa)
{
	if((a[0]>a[1] && a[1]<a[2] && a[2]>a[0]) || (a[0]<a[1] && a[1]>a[2] && a[2]>a[0]) || (a[0]>a[1] && a[1]>a[2] && a[2]<a[0]))
		sa(a, 3);
	if(check_sorted(a, membersa))
		printoutput(a, membersa);
	if(a[0]<a[1] && a[1]>a[2] && a[2]<a[0])
		rra(a, membersa);
	else
		ra(a, membersa);
	printoutput(a, membersa);
}

void sortmain(int *stacka, int *stackb, int membersa, int membersb)
{
	int pivot;

	pivot=average(stacka, membersa);

	
}

void sort(int *stacka, int *stackb, int membersa, int membersb)
{
	if(membersa==2)
	{
		sa(stacka,2);
		printoutput(stacka,2);
	}
	else if(membersa==3)
		sort3(stacka, membersa);
	else
		sortmain(stacka, membersa, stacka, membersb);
}
