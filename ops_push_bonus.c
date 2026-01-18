/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:30:29 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:30:29 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_stack *f, t_stack *t)
{
	t_node	*n;

	if (!f->size)
		return ;
	n = f->top;
	f->top = n->next;
	n->next = t->top;
	t->top = n;
	f->size--;
	t->size++;
}

void	pb_bonus(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pa_bonus(t_stack *a, t_stack *b)
{
	push(b, a);
}
