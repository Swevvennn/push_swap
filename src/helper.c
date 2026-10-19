/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:08:04 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 15:27:03 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	calculate_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	calculate_moves(t_stack *a, t_stack *b, int pos)
{
	int	moves;
	int	target_pos;
	int	size_a;
	int	size_b;

	target_pos = get_target_pos(b, a->arr[pos]);
	size_a = a->top + 1;
	size_b = b->top + 1;
	if ((pos <= size_a / 2 && target_pos <= size_b / 2)
		|| (pos > size_a / 2 && target_pos > size_b / 2))
	{
		if (calculate_rotation_cost(pos, size_a) > \
		calculate_rotation_cost(target_pos, size_b))
			moves = calculate_rotation_cost(pos, size_a);
		else
			moves = calculate_rotation_cost(target_pos, size_b);
	}
	else
		moves = calculate_rotation_cost(pos, size_a) + \
		calculate_rotation_cost(target_pos, size_b);
	return (moves);
}

int	find_best_move(t_stack *a, t_stack *b)
{
	int	i;
	int	min_moves;
	int	best_pos;
	int	moves;

	i = -1;
	min_moves = INT_MAX;
	best_pos = 0;
	while (++i <= a->top)
	{
		moves = calculate_moves(a, b, i);
		if (moves < min_moves)
		{
			min_moves = moves;
			best_pos = i;
		}
	}
	return (best_pos);
}

void	execute_move(t_stack *a, t_stack *b, int pos)
{
	int	target;
	int	size_a;
	int	size_b;

	target = get_target_pos(b, a->arr[pos]);
	size_a = a->top + 1;
	size_b = b->top + 1;
	while (pos > 0 && target > 0 && pos <= size_a / 2 \
		&& target <= size_b / 2)
	{
		rr(a, b);
		pos--;
		target--;
	}
	while (pos > size_a / 2 && target > size_b / 2 \
		&& pos < size_a && target < size_b)
	{
		rrr(a, b);
		pos++;
		target++;
	}
	rotate_a_to_pos(a, pos);
	rotate_b_to_pos(b, target);
	pb(a, b);
}

void	final_rotate(t_stack *a)
{
	int	min_pos;
	int	size;

	size = a->top + 1;
	min_pos = find_min_pos(a);
	if (min_pos <= size / 2)
	{
		while (min_pos--)
			ra(a, 1);
	}
	else
	{
		while (min_pos++ < size)
			rra(a, 1);
	}
}
