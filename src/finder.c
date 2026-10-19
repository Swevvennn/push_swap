/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:55:54 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 15:30:11 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->arr[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int	find_min_pos(t_stack *stack)
{
	int	i;
	int	min;
	int	pos;

	min = stack->arr[0];
	pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->arr[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	get_target_pos(t_stack *b, int num)
{
	int	i;
	int	target;
	int	pos;

	target = INT_MIN;
	pos = 0;
	i = -1;
	while (++i <= b->top)
	{
		if (b->arr[i] < num && b->arr[i] > target)
		{
			target = b->arr[i];
			pos = i;
		}
	}
	if (target == INT_MIN)
	{
		pos = get_target_pos_follow(b);
	}
	return (pos);
}

int	get_target_pos_follow(t_stack *b)
{
	int	max;
	int	i;
	int	pos;

	max = find_max(b);
	i = -1;
	pos = 0;
	while (++i <= b->top)
	{
		if (b->arr[i] == max)
		{
			pos = i;
			break ;
		}
	}
	return (pos);
}
