/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:35:27 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:35:27 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa_bonus(t_stack *a)
{
	t_node	*f;
	t_node	*s;

	if (a->size < 2)
		return ;
	f = a->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	a->top = s;
}

void	sb_bonus(t_stack *b)
{
	t_node	*f;
	t_node	*s;

	if (b->size < 2)
		return ;
	f = b->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	b->top = s;
}
