/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:05:39 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/10 11:31:05 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/push_swap.h"
#include "libft.h"

static bool	check_stack_a(t_push_stack s)
{
	t_node_stack	*a;

	a = s.stack_a->_data;
	while (a->_next)
	{
		if (a->value > a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

static bool	check_stack_b(t_push_stack s)
{
	t_node_stack	*a;

	a = s.stack_b->_data;
	while (a->_next)
	{
		if (a->value < a->_next->value)
			return (1);
		a = a->_next;
	}
	return (0);
}

void	ft_intswap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_median(t_stack *s)
{
	t_node_stack *tmp;
	int	median;
	int	*stack;
	size_t	i;

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
			continue;
		}
	}
	median = stack[s->_size / 2];
	return (median);
}

int quick_sort(t_push_stack s, t_instruc *insn, int id)
{
	return (0);
}