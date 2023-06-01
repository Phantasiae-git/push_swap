/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:58:45 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/01 16:10:27 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_printf("Error - please make sure the numbers fit into an integer and there are no duplicates\n");
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	long	negative;
	long	res1;

	negative = 1;
	i = 0;
	res = 0;
	res1 = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res1 = res * 10 + (str[i] - '0');
		if (res1 < res)
			return ((long)2147483648);
		res = res1;
		i++;
	}
	if (str[i] != '\0')
		return ((long)2147483648);
	else
		return (res * negative);
}

int	check_sorted(int *a, int members)
{
	int	i;

	i = 0;
	while (i + 1 < members)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	long	nbr;
	int		j;
	int		*stacka;
	int		*stackb;
	int		membersa;

	i = 1;
	if (argc < 2)
	{
		ft_printf("not enough parameters, please insert an array of integers separated by spaces");
		return (1);
	}
	while (i < argc)
	{
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (error());
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (error());
			j++;
		}
		i++;
	}
	//divide here
	stacka = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stacka)
		return (error());
	membersa = argc - 1;
	i = -1;
	while ((++i + 1) < argc)
		stacka[i] = ft_atol(argv[i + 1]);
	stackb = NULL;
	if (check_sorted(stacka, membersa))
		ft_printf("Already sorted\n");
	else
	{
		ft_printf("Not sorted\n");
		sort(stacka, stackb, 0, membersa-1);
	}
	return(0);
}
