/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:12:43 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/22 16:16:09 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (size == 2)
	{
		if (a->arr[0] > a->arr[1])
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		turk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (ft_countwords(argv[1]) > 1)
	{
		init_stack(&a, ft_countwords(argv[1]) + argc - 2);
		init_stack(&b, ft_countwords(argv[1]) + argc - 2);
	}
	else
	{
		init_stack(&a, argc - 1);
		init_stack(&b, argc - 1);
	}
	parse_args(argc, argv, &a, &b);
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
