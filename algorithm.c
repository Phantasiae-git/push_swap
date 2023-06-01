/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:05:28 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/27 14:53:47 by rfontes-         ###   ########.fr       */
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

void sortold(int *stacka, int *stackb, int *membersa, int *membersb)
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
		if(stacka[0]>pivot)
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
	sort(stacka, stackb, &((*membersa)/2), membersb);
	sort(stackb, stacka, membersb, membersa);

	while(*membersb)
		pa(&stacka, &stackb, membersa, membersb);
	if(check_sorted(stacka, *membersa) && !stackb[0])
		printoutput(stacka, *membersa);
}

/////////

void swap(int *stacka, int i, int j, int *stackb)
{
	int membersa;
	int numini;
	int numinj;
	int count;
	int count1;

	membersa=sizeof(stacka)/sizeof(stacka[0]);
	numini=stacka[i];
	numinj=stacka[j];
	if(i-1==j || j-1==i)
	{
		while(!((numini==stacka[0] && numinj==stacka[1]) || (numini==stacka[1] && numinj==stacka[0])))
		{
			if(i<(membersa/2+(membersa%2)))
				ra(stacka, membersa);
			else
				rra(stacka, membersa);
		}
		i=0;
		j=1;
	}
	if((i==0 && j==1) || (j==0 && i==1))
	{
		sa(stacka, membersa);
		return;
	}
	//divide here?
	while(numini!=stacka[0])
	{
		ra(stacka, membersa);
		count++;
	}
	pb(&stacka, &stackb, &membersa, &0);
	while(numinj!=stacka[0])
	{
		ra(stacka, membersa);
		count1++;
	}
	pb(&stacka, &stackb, &membersa, &1);
	sb(stackb, 2);
	pa(&stacka, &stackb, &membersa, &2);
	while(count--)
		rra(stacka, membersa);
	pa(&stacka, &stackb, &membersa, &2);
	while(count1--)
		rra(stacka, membersa);
}

int partition(int *stacka, int *stackb, int low, int high)
{
    // temporary pivot
    int pivot = stacka[high];

    int i;
	int j;

	i = (low - 1);
	j=(low-1);

    while (++j < high)
	{
        if (stacka[j] < pivot)
		{
            i++;
            swap(stacka, i, j, stackb);
        }
    }
    swap(stacka, (i + 1), high, stackb);
    return (i + 1);
}

void sort(int *stacka, int *stackb,  int low, int high)
{
	int membersa=high+1;

	if(membersa<4)
	{
		if(membersa==2)
			sa(stacka,2);
		else if(membersa==3)
			sort3(stacka, membersa);
		return;
	}
	if (low < high)
	{
        int split = partition(stacka, stackb, low, high);

        sort(stacka, stackb, low, split - 1);
        sort(stacka, stackb, split + 1, high);
    }
	printoutput(stacka, *membersa);
}