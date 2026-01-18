/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:55 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:34:55 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra_bonus(t_stack *a)
{
	t_node	*f;
	t_node	*l;

	if (a->size < 2)
		return ;
	f = a->top;
	l = a->top;
	while (l->next)
		l = l->next;
	a->top = f->next;
	f->next = NULL;
	l->next = f;
}

void	rb_bonus(t_stack *b)
{
	t_node	*f;
	t_node	*l;

	if (b->size < 2)
		return ;
	f = b->top;
	l = b->top;
	while (l->next)
		l = l->next;
	b->top = f->next;
	f->next = NULL;
	l->next = f;
}
