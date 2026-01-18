/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:01:32 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:01:32 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	atoi_fail(char **nums, t_stack *a)
{
	free_split(nums);
	error_exit(a);
}

int	ft_atoi_safe(char **nums, int j, t_stack *a)
{
	long	r;
	int		sign;
	char	*s;

	s = nums[j];
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		atoi_fail(nums, a);
	r = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			atoi_fail(nums, a);
		r = r * 10 + (*s++ - '0');
		if (r * sign > INT_MAX || r * sign < INT_MIN)
			atoi_fail(nums, a);
	}
	return ((int)(r * sign));
}
