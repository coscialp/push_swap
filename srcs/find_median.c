/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:58:58 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/12 13:50:39 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	ft_intswap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_median(t_stack *s)
{
	t_node_stack	*tmp;
	int				median;
	int				*stack;
	size_t			i;

	i = -1;
	stack = ft_xmalloc(sizeof(int) * s->_size);
	tmp = s->_data;
	while (++i < s->_size)
	{
		stack[i] = tmp->value;
		tmp = tmp->_next;
	}
	i = -1;
	while (++i < s->_size - 1)
	{
		if (stack[i] < stack[i + 1])
		{
			ft_intswap(&stack[i], &stack[i + 1]);
			i = -1;
			continue ;
		}
	}
	median = stack[s->_size / 2];
	return (median);
}
