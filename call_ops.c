/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:54:16 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/21 12:55:39 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int members)
{
	swap(a, members);
	ft_printf("sa\n");
}

void	sb(int *b, int members)
{
	swap(b, members);
	ft_printf("sb");
}

void	ss(int *a, int *b, int membersa, int membersb)
{
	swap(a, membersa);
	swap(b, membersb);
	ft_printf("ss");
}

void	pa(int *a, int *b, int membersa, int membersb)
{
	push(a, b, membersa, membersb);
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int membersa, int membersb)
{
	push(b, a, membersb, membersa);
	ft_printf("pb\n");
}

void	ra(int *a, int members)
{
	rotate(a, members);
	ft_printf("ra\n");
}

void	rb(int *b, int members)
{
	rotate(b, members);
	ft_printf("rb\n");
}

void	rr(int *a, int *b, int membersa, int membersb)
{
	rotate(a, membersa);
	rotate(b, membersb);
	ft_printf("rr\n");
}

void	rra(int *a, int members)
{
	revrotate(a, members);
	ft_printf("rra\n");
}

void	rrb(int *b, int members)
{
	revrotate(b, members);
	ft_printf("rb\n");
}

void	rrr(int *a, int *b, int membersa, int membersb)
{
	revrotate(a, membersa);
	revrotate(b, membersb);
	ft_printf("rrr\n");
}
