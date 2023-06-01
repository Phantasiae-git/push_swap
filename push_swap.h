/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:01:28 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/01 16:52:27 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

// typedef struct stack
// {
// 	int n;
// 	struct stack	*next;
// }	t_stack;

void	swap(int *a, int members);
void	swapnum(int *stacka, int *arr, int *stackb, int membersa);
void	sort(int *stacka, int *stackb, int low, int high);
void	swapold(int *a, int members);
void	push(int **a, int **b, int *membersa, int membersb);
void	rotate(int *a, int members);
void	revrotate(int *a, int members);
void	sa(int *a, int members);
void	sb(int *b, int members);
void	ss(int *a, int *b, int membersa, int membersb);
void	pa(int **a, int **b, int *membersa, int membersb);
void	pb(int **a, int **b, int *membersa, int membersb);
void	ra(int *a, int members);
void	rb(int *b, int members);
void	rr(int *a, int *b, int membersa, int membersb);
void	rra(int *a, int members);
void	rrb(int *b, int members);
void	rrr(int *a, int *b, int membersa, int membersb);
int		check_sorted(int *a, int members);
void	printoutput(int *stacka, int membersa);
int     average(int *stack, int members);
int     abs(int a);

#endif