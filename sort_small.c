/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:36 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:36 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*t;

	t = a->top;
	while (t && t->next)
	{
		if (t->value > t->next->value)
			return (0);
		t = t->next;
	}
	return (1);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->top->next->next->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

int	find_min_index(t_stack *s)
{
	t_node	*t;
	int		min;

	t = s->top;
	min = t->index;
	while (t)
	{
		if (t->index < min)
			min = t->index;
		t = t->next;
	}
	return (min);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = pos(a, find_min_index(a));
		if (min_pos == 0)
			pb(a, b);
		else if (min_pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	sort_3(a);
	while (b->size)
		pa(a, b);
}
