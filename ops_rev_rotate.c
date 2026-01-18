/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:45 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:45 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = stack->top;
	if (stack->size < 2)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = stack->top;
	if (stack->size < 2)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	write(1, "rrb\n", 4);
}
