/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:18 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:18 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* parsing */
void	parse_input(int ac, char **av, t_stack *a);
char	**split(char const *s);
int		ft_atoi_safe(char **nums, int j, t_stack *a);
void	free_split(char **nums);

/* stack */
void	stack_init(t_stack *s);
void	stack_add_back(t_stack *s, int value);
void	stack_clear(t_stack *s);

/* indexing */
void	index_stack(t_stack *a);

/* operations */
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);

/* sorting */
int		is_sorted(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
int		pos(t_stack *s, int idx);

/* error */
void	error_exit(t_stack *a);

#endif
