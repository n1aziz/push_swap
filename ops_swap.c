/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:55 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:55 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
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
	write(1, "sa\n", 3);
}
