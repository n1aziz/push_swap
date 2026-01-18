/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:36 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:36 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from->size)
		return ;
	node = from->top;
	from->top = node->next;
	node->next = to->top;
	to->top = node;
	from->size--;
	to->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
