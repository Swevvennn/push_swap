/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:49:02 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/19 14:47:38 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	init_stack(t_stack *stack, int size)
{
	stack->arr = malloc(sizeof(int) * size);
	if (!stack->arr)
		error_exit(NULL, NULL, NULL);
	stack->top = -1;
	stack->size = size;
}

void	free_stack(t_stack *stack)
{
	if (stack->arr)
		free(stack->arr);
}
