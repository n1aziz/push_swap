/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:26 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/17 20:36:32 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_stack *s, int idx)
{
	t_node	*t;
	int		i;

	t = s->top;
	i = 0;
	while (t)
	{
		if (t->index == idx)
			return (i);
		i++;
		t = t->next;
	}
	return (0);
}

static void	push_chunks(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk;

	if (a->size <= 100)
		chunk = 15;
	else
		chunk = 33;
	i = 0;
	while (a->size)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

static void	push_back(t_stack *a, t_stack *b)
{
	int	max;
	int	p;

	while (b->size)
	{
		max = b->size - 1;
		p = pos(b, max);
		if (p <= b->size / 2)
			while (b->top->index != max)
				rb(b);
		else
			while (b->top->index != max)
				rrb(b);
		pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
	{
		push_chunks(a, b);
		push_back(a, b);
	}
}
