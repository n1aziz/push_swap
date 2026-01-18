/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:03:44 by azel-mah          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:44 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char const *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			c++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (c);
}

static char	*word(char const *s, int a, int b)
{
	char	*w;
	int		i;

	w = malloc(b - a + 1);
	if (!w)
		return (NULL);
	i = 0;
	while (a < b)
		w[i++] = s[a++];
	w[i] = 0;
	return (w);
}

char	**split(char const *s)
{
	char	**r;
	int		i;
	int		j;
	int		st;

	r = malloc(sizeof(char *) * (count(s) + 1));
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		st = i;
		while (s[i] && s[i] != ' ')
			i++;
		if (st < i)
			r[j++] = word(s, st, i);
	}
	r[j] = NULL;
	return (r);
}
