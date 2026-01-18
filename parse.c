/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:03 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:03 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **nums)
{
	int	i;

	if (!nums)
		return ;
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

static int	is_dup(t_stack *a, int v)
{
	t_node	*t;

	t = a->top;
	while (t)
	{
		if (t->value == v)
			return (1);
		t = t->next;
	}
	return (0);
}

static void	parse_fail(char **nums, t_stack *a)
{
	free_split(nums);
	error_exit(a);
}

void	parse_input(int ac, char **av, t_stack *a)
{
	char	**nums;
	int		i;
	int		j;
	int		v;

	i = 1;
	while (i < ac)
	{
		nums = split(av[i]);
		if (!nums || !nums[0])
			parse_fail(nums, a);
		j = 0;
		while (nums[j])
		{
			v = ft_atoi_safe(nums, j, a);
			if (is_dup(a, v))
				parse_fail(nums, a);
			stack_add_back(a, v);
			j++;
		}
		free_split(nums);
		i++;
	}
}
