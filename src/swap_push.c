/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:57:28 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 14:24:21 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	sa(t_stack *a, int print)
{
	int	tmp;

	if (a->top < 1)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	if (print)
		ft_putstr("sa\n");
}

void	sb(t_stack *b, int print)
{
	int	tmp;

	if (b->top < 1)
		return ;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	if (print)
		ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr("ss\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->top < 0)
		return ;
	b->top++;
	i = b->top + 1;
	while (--i > 0)
		b->arr[i] = b->arr[i - 1];
	b->arr[0] = a->arr[0];
	i = -1;
	while (++i < a->top)
		a->arr[i] = a->arr[i + 1];
	a->top--;
	ft_putstr("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->top < 0)
		return ;
	a->top++;
	i = a->top + 1;
	while (--i > 0)
		a->arr[i] = a->arr[i - 1];
	a->arr[0] = b->arr[0];
	i = -1;
	while (++i < b->top)
		b->arr[i] = b->arr[i + 1];
	b->top--;
	ft_putstr("pa\n");
}
