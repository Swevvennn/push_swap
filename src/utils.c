/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:58:00 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/19 14:44:19 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	ft_atoi(const char *str, t_stack *a, t_stack *b, char **tab)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			error_exit(a, b, tab);
		i++;
	}
	if (str[i] != '\0')
		error_exit(a, b, tab);
	return ((int)(result * sign));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_exit(t_stack *a, t_stack *b, char **tab)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	ft_free(tab);
	exit(1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
