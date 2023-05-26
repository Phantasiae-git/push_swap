/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:05:28 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/26 20:52:46 by phantasiae       ###   ########.fr       */
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
	//exit(0);
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
	//printoutput(a, membersa);
}

void sort(int *stacka, int *stackb, int *membersa, int *membersb)
{
	int pivot;
	int i;
	int rotations;
	int membersaold;
	
	rotations=0;
	if(*membersa<4)
	{
		if(*membersa==2)
			sa(stacka,2);
		else if(*membersa==3)
			sort3(stacka, *membersa);
		return;
	}
	pivot=stacka[average(stacka, *membersa)];
	ft_printf("avg=%i\n", pivot);
	i=-1;
	membersaold=*membersa;
	while (++i<membersaold)
	{
		if(stacka[0]<pivot)
			pb(&stacka, &stackb, membersa, membersb);
		else
		{
			ra(stacka, *membersa);
			rotations++;
		}
		printoutput(stacka, *membersa);
		printoutput(stackb, *membersb);
	}
	while (rotations--)
		rra(stacka, *membersa);
	printoutput(stacka, *membersa);
	printoutput(stackb, *membersb);
	sort(stacka, stackb, membersa, membersb);
	sort(stackb, stacka, membersb, membersa);

	while(*membersb)
		pa(&stacka, &stackb, membersa, membersb);
	if(check_sorted(stacka, *membersa) && !stackb[0])
		printoutput(stacka, *membersa);
}
