/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:38:28 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 17:38:28 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	parse_input(ac, av, &a);
	line = get_next_line(0);
	while (line)
	{
		exec_instruction(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	check_result(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
