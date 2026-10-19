/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:20:30 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/22 16:39:11 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}

void	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	char **tab;
	int	j;
	int	i;

	i = 0;
	tab = ft_split(argv[++i]);
	j = -1;
	while (tab[++j])
		a->arr[a->top++ + 1] = ft_atoi(tab[j], a, b, tab);
	ft_free(tab);
	while (++i < argc)
	{	
		if (ft_countwords(argv[i]) > 1)
			error_exit(a, b, NULL);
		a->arr[a->top++ + 1] = ft_atoi(argv[i], a, b, NULL);
	}
	if (has_duplicates(a->arr, a->top + 1))
		error_exit(a, b, NULL);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->top)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
	}
	return (1);
}

char	**ft_split(char *s)
{
	char	**res;
	int		i;
	int		len;
	int		word;

	i = 0;
	word = 0;
	res = malloc((ft_countwords(s) + 1) * sizeof(char *));
	if (!res || !s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	while (s[i])
	{
		len = ft_wordlen((char *)&s[i]);
		res[word] = malloc(sizeof(char) * (len + 1));
		if (!res[word])
			return (ft_free(res));
		ft_strlcpy(res[word++], &s[i], len + 1);
		i += len;
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
	}
	res[word] = NULL;
	return (res);
}
