/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:31:36 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:31:36 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra_bonus(t_stack *a)
{
	t_node	*p;
	t_node	*l;

	p = NULL;
	l = a->top;
	if (a->size < 2)
		return ;
	while (l->next)
	{
		p = l;
		l = l->next;
	}
	p->next = NULL;
	l->next = a->top;
	a->top = l;
}

void	rrb_bonus(t_stack *b)
{
	t_node	*p;
	t_node	*l;

	p = NULL;
	l = b->top;
	if (b->size < 2)
		return ;
	while (l->next)
	{
		p = l;
		l = l->next;
	}
	p->next = NULL;
	l->next = b->top;
	b->top = l;
}
