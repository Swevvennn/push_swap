/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:06 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/22 12:20:20 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
}	t_stack;

int		ft_atoi(const char *str, t_stack *a, t_stack *b, char **tab);
int		ft_strlen(char *str);
void	error_exit(t_stack *a, t_stack *b, char **tab);
void	ft_putstr(char *str);

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	init_stack(t_stack *stack, int size);
void	free_stack(t_stack *stack);

void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);

void	rotate_a_to_pos(t_stack *a, int pos);
void	rotate_b_to_pos(t_stack *b, int pos);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

int		has_duplicates(int *arr, int size);
void	parse_args(int argc, char **argv, t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
char	**ft_split(char *s);

int		ft_countwords(char const *s);
void	*ft_free(char **r);
int		ft_wordlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

void	sort_stack(t_stack *a, t_stack *b);

int		calculate_rotation_cost(int pos, int size);
int		calculate_moves(t_stack *a, t_stack *b, int pos);
int		find_best_move(t_stack *a, t_stack *b);
void	execute_move(t_stack *a, t_stack *b, int pos);
void	final_rotate(t_stack *a);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		get_target_pos(t_stack *b, int num);
int		get_target_pos_follow(t_stack *b);

#endif