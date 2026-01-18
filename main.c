/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:18 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:02:18 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	parse_input(ac, av, &a);
	index_stack(&a);
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	stack_clear(&a);
	return (0);
}
