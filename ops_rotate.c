/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:51 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:51 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}
