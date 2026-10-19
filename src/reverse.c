/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:58:45 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/16 15:28:01 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	rra(t_stack *a, int print)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	i = a->top + 1;
	tmp = a->arr[a->top];
	while (--i > 0)
		a->arr[i] = a->arr[i - 1];
	a->arr[0] = tmp;
	if (print)
		ft_putstr("rra\n");
}

void	rrb(t_stack *b, int print)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[b->top];
	i = b->top + 1;
	while (--i > 0)
		b->arr[i] = b->arr[i - 1];
	b->arr[0] = tmp;
	if (print)
		ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr("rrr\n");
}
