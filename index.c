/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:13 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:13 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		idx;

	i = a->top;
	while (i)
	{
		idx = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				idx++;
			j = j->next;
		}
		i->index = idx;
		i = i->next;
	}
}
