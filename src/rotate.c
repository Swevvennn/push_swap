/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:26:49 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 15:28:12 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	rotate_a_to_pos(t_stack *a, int pos)
{
	int	size;

	size = a->top + 1;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (pos++ < size)
			rra(a, 1);
	}
}

void	rotate_b_to_pos(t_stack *b, int pos)
{
	int	size;

	size = b->top + 1;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, 1);
	}
	else
	{
		while (pos++ < size)
			rrb(b, 1);
	}
}

void	ra(t_stack *a, int print)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	tmp = a->arr[0];
	i = -1;
	while (++i < a->top)
		a->arr[i] = a->arr[i + 1];
	a->arr[a->top] = tmp;
	if (print)
		ft_putstr("ra\n");
}

void	rb(t_stack *b, int print)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[0];
	i = -1;
	while (++i < b->top)
		b->arr[i] = b->arr[i + 1];
	b->arr[b->top] = tmp;
	if (print)
		ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr("rr\n");
}
