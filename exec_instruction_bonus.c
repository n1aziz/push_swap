/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:26:49 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:26:49 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	error_exit_bonus(t_stack *a, t_stack *b, char *line)
{
	stack_clear(a);
	stack_clear(b);
	free(line);
	write(2, "Error\n", 6);
	exit(1);
}

static int	streq(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (a[i] == b[i]);
}

static int	exec_double(char *cmd, t_stack *a, t_stack *b)
{
	if (streq(cmd, "ss\n"))
	{
		sa_bonus(a);
		sb_bonus(b);
	}
	else if (streq(cmd, "rr\n"))
	{
		ra_bonus(a);
		rb_bonus(b);
	}
	else if (streq(cmd, "rrr\n"))
	{
		rra_bonus(a);
		rrb_bonus(b);
	}
	else
		return (0);
	return (1);
}

static int	exec_single(char *cmd, t_stack *a, t_stack *b)
{
	if (streq(cmd, "sa\n"))
		sa_bonus(a);
	else if (streq(cmd, "sb\n"))
		sb_bonus(b);
	else if (streq(cmd, "pa\n"))
		pa_bonus(a, b);
	else if (streq(cmd, "pb\n"))
		pb_bonus(a, b);
	else if (streq(cmd, "ra\n"))
		ra_bonus(a);
	else if (streq(cmd, "rb\n"))
		rb_bonus(b);
	else if (streq(cmd, "rra\n"))
		rra_bonus(a);
	else if (streq(cmd, "rrb\n"))
		rrb_bonus(b);
	else
		return (0);
	return (1);
}

void	exec_instruction(char *cmd, t_stack *a, t_stack *b)
{
	if (exec_single(cmd, a, b))
		return ;
	if (exec_double(cmd, a, b))
		return ;
	error_exit_bonus(a, b, cmd);
}

/*void	exec_instruction(char *cmd, t_stack *a, t_stack *b)
{
	if (streq(cmd, "sa\n"))
		sa_bonus(a);
	else if (streq(cmd, "sb\n"))
		sb_bonus(b);
	else if (streq(cmd, "ss\n"))
	{
		sa_bonus(a);
		sb_bonus(b);
	}
	else if (streq(cmd, "pa\n"))
		pa_bonus(a, b);
	else if (streq(cmd, "pb\n"))
		pb_bonus(a, b);
	else if (streq(cmd, "ra\n"))
		ra_bonus(a);
	else if (streq(cmd, "rb\n"))
		rb_bonus(b);
	else if (streq(cmd, "rr\n"))
	{
		ra_bonus(a);
		rb_bonus(b);
	}
	else if (streq(cmd, "rra\n"))
		rra_bonus(a);
	else if (streq(cmd, "rrb\n"))
		rrb_bonus(b);
	else if (streq(cmd, "rrr\n"))
	{
		rra_bonus(a);
		rrb_bonus(b);
	}
	else
		error_exit_bonus(a, b);
}*/
