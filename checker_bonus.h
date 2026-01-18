/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:14:53 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/16 15:14:53 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

/* bonus only */
void	exec_instruction(char *cmd, t_stack *a, t_stack *b);

/* operations */
void	sa_bonus(t_stack *a);
void	sb_bonus(t_stack *b);
void	pb_bonus(t_stack *a, t_stack *b);
void	pa_bonus(t_stack *a, t_stack *b);
void	ra_bonus(t_stack *a);
void	rra_bonus(t_stack *a);
void	rb_bonus(t_stack *b);
void	rrb_bonus(t_stack *b);

#endif
