/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:49 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:49 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

void	stack_add_back(t_stack *s, int v)
{
	t_node	*n;
	t_node	*t;

	n = malloc(sizeof(t_node));
	if (!n)
		error_exit(s);
	n->value = v;
	n->index = -1;
	n->next = NULL;
	if (!s->top)
		s->top = n;
	else
	{
		t = s->top;
		while (t->next)
			t = t->next;
		t->next = n;
	}
	s->size++;
}

void	stack_clear(t_stack *s)
{
	t_node	*t;

	while (s->top)
	{
		t = s->top->next;
		free(s->top);
		s->top = t;
	}
}
