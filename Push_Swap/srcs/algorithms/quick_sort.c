/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:05:39 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/09 17:50:51 by coscialp         ###   ########lyon.fr   */
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
	static int	value_median;
	static int	begin = 0;
	static int	second_part = 0;
	static int	a_or_b = -1;
	static int	nb_insn = 0;

	nb_insn++;
	if (begin == 0)
	{
		value_median = find_median(s.stack_a);
		begin = 1;
	}
	if (s.stack_a->_size <= s.stack_b->_size && s.stack_a->_size >= s.stack_b->_size - 1)
		second_part = 1;
	if (second_part == 0)
	{
		if (s.stack_a->_data->value <= value_median)
		{
			insn[PB].func(&s);
			s.algo[id]->pushback(s.algo[id], "pb");
		}
		else
		{
			insn[RA].func(&s);
			s.algo[id]->pushback(s.algo[id], "ra");
		}
	}
	else
	{
		if (!check_stack_b(s) && !check_stack_a(s))
		{
			insn[PA].func(&s);
			s.algo[id]->pushback(s.algo[id], "pa");
			return (nb_insn);
		}
		if (a_or_b == -1 && (check_stack_b(s) || check_stack_a(s)))
		{
			ft_dprintf(2, "f %d\n", nb_insn);
			if (!check_stack_a(s))
				a_or_b = -a_or_b;
			else if (s.stack_a->_data->value > s.stack_a->_data->_next->value)
			{
				insn[SA].func(&s);
				s.algo[id]->pushback(s.algo[id], "sa");
			}
			else if (s.stack_a->_data->value < s.stack_a->_data->_next->value && s.stack_a->_data->value < s.stack_a->last(s.stack_a)->value)
			{
				insn[RRA].func(&s);
				s.algo[id]->pushback(s.algo[id], "rra");
			}
			else
			{
				insn[RA].func(&s);
				s.algo[id]->pushback(s.algo[id], "ra");
			}
		}
		if (a_or_b == 1 && (check_stack_b(s) || check_stack_a(s)))
		{
			ft_dprintf(2, "g %d\n", nb_insn);
			if (!check_stack_b(s))
				a_or_b = -a_or_b;
			if (s.stack_b->_data->value < s.stack_b->_data->_next->value)
			{
				insn[SB].func(&s);
				s.algo[id]->pushback(s.algo[id], "sb");
			}
			else if (s.stack_b->_data->value > s.stack_b->_data->_next->value && s.stack_b->_data->value > s.stack_b->last(s.stack_b)->value)
			{
				insn[RRB].func(&s);
				s.algo[id]->pushback(s.algo[id], "rrb");
			}
			else
			{
				insn[RB].func(&s);
				s.algo[id]->pushback(s.algo[id], "rb");
			}
		}
		a_or_b = -a_or_b;
	}
	return (nb_insn);
}