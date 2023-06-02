/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:05:28 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/02 18:55:39 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printoutput(int *stacka, int membersa)
{
	int	i;

	i = 0;
	while (i < membersa)
		ft_printf("%i ", stacka[i++]);
	ft_printf("Success!\n");
	//exit(0);
}

void	sort3(int *a, int membersa)
{
	if ((a[0] > a[1] && a[1] < a[2] && a[2] > a[0]) || (a[0] < a[1]
			&& a[1] > a[2] && a[2] > a[0]) || (a[0] > a[1] && a[1] > a[2]
			&& a[2] < a[0]))
		sa(a, 3);
	if (check_sorted(a, membersa))
		printoutput(a, membersa);
	if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		rra(a, membersa);
	else
		ra(a, membersa);
	printoutput(a, membersa);
}

/*void sortold(int *stacka, int *stackb, int *membersa, int *membersb)
{
	int	pivot;
	int	i;
	int	rotations;
	int	membersaold;
	int	numini;
	int	numinj;
	int	count;
	int	count1;
	int	membersb;

	
	rotations=0;
	if(*membersa<4)
	{
		if(*membersa==2)
			sa(stacka,2);
		else if(*membersa==3)
			sort3(stacka, *membersa);
		return ;
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
}*/
/////////
int	*swapnum(int *stacka, int *arr, int *stackb, int membersa)
{
	int numini;
	int numinj;
	int count;
	int count1;
	int membersb;
	numini = stacka[arr[0]];
	numinj = stacka[arr[1]];
	count = 0;
	count1 = 0;
	if (arr[0] == arr[1])
		return (stacka);
	if (arr[0] - 1 == arr[1] || arr[1] - 1 == arr[0])
	{
		while (!((numini == stacka[0] && numinj == stacka[1])
				|| (numini == stacka[1] && numinj == stacka[0])))
		{
			if (arr[0] < (membersa / 2 + (membersa % 2)))
			{
				ra(stacka, membersa);
				count++;
			}
			else
			{
				rra(stacka, membersa);
				count1++;
			}
		}
		arr[0] = 0;
		arr[1] = 1;
	}
	if ((arr[0] == 0 && arr[1] == 1) || (arr[1] == 0 && arr[0] == 1))
	{
		if (stacka[0] > stacka[1])
			sa(stacka, membersa);
		while (count--)
			rra(stacka, membersa);
		while (count1--)
			ra(stacka, membersa);
		return (stacka);
	}
	//divide here?
	while (numini != stacka[0])
	{
		ra(stacka, membersa);
		count++;
	}
	membersb = 0;
	pb(&stacka, &stackb, &membersa, &membersb);
	while (numinj != stacka[0])
	{
		ra(stacka, membersa);
		count1++;
	}
	pb(&stacka, &stackb, &membersa, &membersb);
	sb(stackb, 2);
	pa(&stacka, &stackb, &membersa, &membersb);
	while (count1--)
		rra(stacka, membersa);
	pa(&stacka, &stackb, &membersa, &membersb);
	while (count--)
		rra(stacka, membersa);
	return (stacka);
}

int	*partition(int *stacka, int *stackb, int low, int high)
{
	int	pivot;
	int	membersa;
	int	arr[2];
	int	temp[2];

	// temporary pivot
	pivot = stacka[high];
	membersa = *members();
	arr[0] = (low - 1);
	arr[1] = (low - 1);
	while (++(arr[1]) < high)
	{
		if (stacka[arr[1]] < pivot)
		{
			(arr[0])++;
			temp[0] = arr[0];
			temp[1] = arr[1];
			stacka = swapnum(stacka, arr, stackb, membersa);
			arr[0] = temp[0];
			arr[1] = temp[1];
		}
	}
	(arr[0])++;
	arr[1] = high;
	stacka = swapnum(stacka, arr, stackb, membersa);
	check_sorted(stacka, membersa);
	return (stacka);
}

void	sort(int *stacka, int *stackb, int low, int high)
{
	int	membersa;
	int	pivot;
	int	split;

	membersa = *members();
	if (low < high)
	{
		pivot = stacka[high];
		stacka = partition(stacka, stackb, low, high);
		split = 0;
		while (stacka[split] != pivot)
			split++;
		sort(stacka, stackb, low, split - 1);
		sort(stacka, stackb, split + 1, high);
	}
}
