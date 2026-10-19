/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:17:15 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 16:11:28 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->arr[0];
	mid = a->arr[1];
	bot = a->arr[2];
	if (top > mid && mid < bot && top < bot)
		sa(a, 1);
	else if (top > mid && mid > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, 1);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->top > 2)
	{
		min_pos = find_min_pos(a);
		if (min_pos <= a->top / 2)
		{
			while (min_pos--)
				ra(a, 1);
		}
		else
		{
			while (min_pos++ <= a->top)
				rra(a, 1);
		}
		pb(a, b);
	}
	if (a->top == 2 && !is_sorted(a))
		sort_three(a);
	else if (a->top == 1 && a->arr[0] > a->arr[1])
		sa(a, 1);
	while (b->top >= 0)
		pa(a, b);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	best;

	pb(a, b);
	pb(a, b);
	while (a->top >= 0)
	{
		best = find_best_move(a, b);
		execute_move(a, b, best);
	}
	while (b->top >= 0)
		pa(a, b);
	final_rotate(a);
}
